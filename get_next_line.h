#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);

void	*ft_memset(void *b, char c, size_t len);
size_t	ft_strlen(const char *s);
size_t	find(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
