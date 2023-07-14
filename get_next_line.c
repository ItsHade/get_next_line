#include "get_next_line.h"


char *ft_get_line(char *stash)
{
    int i;
    char *line;

    if (!stash || !stash[0])
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = (char *)malloc((1 + i) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char *ft_new_stash(char *stash)
{
    char *str;
    int i;
    int a;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\0')
    {
        free(stash);
        return (NULL);
    }
    i += (stash[i] == '\n');
    str = (char *)malloc(1 + ft_strlen(stash) - i);
    if (!str)
        return (NULL);
    a = 0;
    while (stash[i + a])
    {
        str[a] = stash[i + a];
        a++;
    }
    str[a] = '\0';
    free(stash);
    return (str);
}

char *get_next_line(int fd)
{
    char *buffer;
    int nb_bytes;
    static char *stash;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    nb_bytes = 1;
    buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
    if (!buffer)
        return (NULL);
    while (!(ft_strchr(stash, '\n')) && nb_bytes != 0)
    {
        nb_bytes = read(fd, buffer, BUFFER_SIZE);
        if (nb_bytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[nb_bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    buffer = ft_get_line(stash);
    stash = ft_new_stash(stash);
    return (buffer);
}
/*
int main()
{
    int fd;
    char *line;
    int i;

    // Ouvrir le fichier en lecture
    fd = open("test.txt", O_RDONLY);
    i = 1;
    if (fd == -1)
    {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lire les lignes du fichier jusqu'à la fin
    while (i < 8)
    {
        line = get_next_line(fd);
        printf("#############\n");
        printf("%s\n", line);
        free(line); // Libérer la mémoire allouée par get_next_line
        i++;
    }

    // Fermer le fichier
    close(fd);

    return 0;
}
*/