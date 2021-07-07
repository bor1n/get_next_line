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

	if (s == 0)
		return (0);
	res = 0;
	while (*s != 0)
	{
		res++;
		s++;
	}
	return (res);
}

size_t	find(const char *s, int c)
{
	size_t	length;
	size_t	count;

	count = 0;
	length = ft_strlen(s);
	while (count < length + 1)
	{
		if (*s == (unsigned char) c)
			return (count);
		count++;
		s++;
	}
	return (-1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		counter;

	counter = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == 0)
		return (0);
	while (s1 && s1[counter])
	{
		result[counter] = s1[counter];
		counter++;
	}
	while (*s2)
	{
		result[counter] = *s2;
		s2++;
		counter++;
	}
	result[counter] = 0;
	free((char *)s1);
	return (result);
}
