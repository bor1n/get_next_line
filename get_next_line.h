#ifndef GET_NEXT_LINE_C
# define GET_NEXT_LINE_C

# include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

int get_next_line(int fd, char **line);

void	*ft_memset(void *b, char c, size_t len);
size_t	ft_strlen(const char *s);

#endif

