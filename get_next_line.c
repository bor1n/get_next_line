#include "get_next_line.h"

int    process(char **line, char **buffer)
{
    char *temp;

    temp = *line;
    while (*temp)
        temp++;
    while(**buffer)
    {
        if (**buffer == -1)
            return (-1);
        (*temp) = **buffer;
        (*buffer)++;
        if (*temp == '\n')
            return (1);
        temp++;
    }
    return (0);
}

int get_next_line(int fd, char **line)
{
    static char *buffer;
    int size;
    static char *temp;
    int result;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    ft_memset(*line, 0, ft_strlen(*line));
    if (buffer != 0)
    {
        result = process(line, &buffer);
        if (result == 1)
            return (1);
        if (result == -1)
            return (-1);
    }
    if (buffer == 0)
        buffer = malloc(BUFFER_SIZE + 1);
    if (temp == 0)
        temp = buffer;
    if (buffer == 0)
        return (-1);
    while(1)
    {
        buffer = temp;
        ft_memset(buffer, 0, BUFFER_SIZE);
        size = read(fd, buffer, BUFFER_SIZE);
        buffer[BUFFER_SIZE] = 0;
        if (size == 0)
            return (0);
        result = process(line, &buffer);
        if (result == -1)
            return (0);
        if (result == 1)
            return (1);
    }
}