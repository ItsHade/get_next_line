#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char *ft_strchr(char *s, int c)
{
    size_t i;

    if (!s)
        return (NULL);
    if (c == 0)
    {
        i = ft_strlen((char *)s);
        return (&s[i]);
    }
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}

char *ft_strjoin(char *stash, char *buff)
{
    char *ptr;

    if (!stash)
    {
        stash = (char *)malloc(1 * sizeof(char));
        stash[0] = '\0';
    }
    if (!stash || !buff)
        return (NULL);
    ptr = (char *)malloc((1 + ft_strlen(stash) + ft_strlen(buff)) * sizeof(char));
    if (!ptr)
        return (NULL);
    ptr = ft_strjoin2(ptr, stash, buff);
    free(stash);
    return (ptr);
}

char *ft_strjoin2(char *ptr, char *s1, char *s2)
{
    size_t i;
    size_t a;

    i = 0;
    while (s1 && s1[i])
    {
        ptr[i] = s1[i];
        i++;
    }
    a = 0;
    while (s2 && s2[a])
    {
        ptr[i + a] = s2[a];
        a++;
    }
    ptr[i + a] = '\0';
    return (ptr);
}