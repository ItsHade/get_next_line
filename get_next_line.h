#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

size_t ft_strlen(char *str);
char *get_next_line(int fd);
char *ft_get_line(char *src);
char *ft_strchr(char *s, int c);
char *ft_new_stash(char *start);
char *ft_strjoin(char *start, char *buff);
char *ft_strjoin2(char *dest, char *s1, char *s2);

#endif