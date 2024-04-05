#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
char    *read_file_ft(int fd, char *overall_buffer);
char    *get_line_ft(char *overall_buffer);
char    *line_management(char *overall_buffer);
char    *free_and_join(char *overall_buffer, char *buffer);
size_t  ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);

#endif