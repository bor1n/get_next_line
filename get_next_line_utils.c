#include "get_next_line.h"

void	*ft_memset(void *b, char c, size_t len)
{
    size_t	counter;

    counter = 0;
    while (counter < len)
    {
        *(unsigned char *) &b[counter] = c;
        counter++;
    }
    return (b);
}

size_t	ft_strlen(const char *s)
{
    size_t	res;

    res = 0;
    while (*s != 0)
    {
        res++;
        s++;
    }
    return (res);
}
