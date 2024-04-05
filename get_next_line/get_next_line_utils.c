#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (NULL);
    if (c == '\0')
        return (&s[i]);
    while(s[i] != c && s[i] != '\0')
        i++;
    if (s[i] == c)
        return (&s[i]);
    else
        return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *p;
    size_t  i;
    size_t  j;

    i = 0;
    if (!s1)
        return (s2);
    p = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!p)
        return (NULL);
    while (s1[i] != '\0')
    {
        p[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j] != '\0')
    {
        p[i] = s2[j];
        i++;
        j++;
    }
    p[i] = '\0';
    return (p);
}