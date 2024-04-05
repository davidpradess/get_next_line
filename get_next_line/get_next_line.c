#include "get_next_line.h"

char *free_and_join(char *overall_buffer, char *buffer)
{
	char *temp;

	temp = ft_strjoin(overall_buffer, buffer);
	free(overall_buffer);
	return (temp);
}

char *line_management(char *overall_buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (overall_buffer[i] && overall_buffer[i] != '\n')
	{
		i++;
	}
	if (!overall_buffer[i])
	{
		free (overall_buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(ft_strlen(overall_buffer) - i + 1);
	i++;
	j = 0;
	while (overall_buffer[i])
	{
		new_buffer[j] = overall_buffer[i];
		j++;
		i++;
	}
	free (overall_buffer);
	return (new_buffer);
}

char *get_line_ft(char *overall_buffer)
{
	int		i;
	char	*line;

	i = 0;
	printf("String here is: %s\n", overall_buffer);
	if (!overall_buffer[i])
		return (NULL);
	while (overall_buffer[i] && overall_buffer[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (overall_buffer[i] && overall_buffer[i] != '\n')
	{
		line[i] = overall_buffer[i];
		i++;
	}
	if (overall_buffer[i] == '\n')
	{
		line[i] = overall_buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_file_ft(int fd, char *overall_buffer)
{
	ssize_t	bytes_read;
	char	*buffer;

	printf("11");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	printf("12");
	bytes_read = 1;
	printf("13");
	while (bytes_read > 0)
	{
		printf("14");
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("15");
		if (bytes_read == -1)
		{
			printf("16");
			free(buffer);
			free(overall_buffer);
			overall_buffer = NULL;
			return (NULL);
		}
		printf("17");
		buffer[bytes_read] = '\0';
		printf("18");
		printf("\n\n overall_buffer: %s, buffer: %s, bytes_read: %zi\n\n", overall_buffer, buffer, bytes_read);
		overall_buffer = free_and_join(overall_buffer, buffer);
		printf("19");
		if (ft_strchr(overall_buffer, '\n'))
		{
			printf("20");
			break;
		}
		printf("21");
	}
	printf("22");
	free (buffer);
	printf("23");
	return (overall_buffer);
}

char *get_next_line(int fd)
{
	static char	*overall_buffer;
	char		*line;

	printf("uno");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		
		return (NULL);
	}
	printf("tres");
	overall_buffer = read_file_ft(fd, overall_buffer);
	printf("cuatro, str : %s", overall_buffer);
	if (!overall_buffer)
		return (NULL);
	printf("cinco");
	line = get_line_ft(overall_buffer);
	printf("seis");
	overall_buffer = line_management(overall_buffer);
	printf("siete");
	return (line);
}

int main(void)
{
	int		file;
	char 	*line;

	printf("1");
	file = open("poem.txt", O_RDONLY);
	printf("2");
	if (file == -1)
	{
		printf("3");
		printf("Error opening file\n");
		return (1);
	}	
	while ((line = get_next_line(file)) != NULL)
	{
		printf("4");
		printf("%s", line);
		free(line);
	}
	printf("5");
	close(file);
	return (0);
}