#include "get_next_line.h"

char	*end_of_file(char **line)
{
	if (**line == 0)
		return (0);
	return (*line);
}

void	move(char *buffer, int index)
{
	int	i;

	i = 0;
	while (buffer[index])
		buffer[i++] = buffer[index++];
	buffer[i] = buffer[index];
}

void	from_buffer(char *buffer, char **line)
{
	int	newline;

	newline = find(buffer, '\n');
	buffer[newline++] = 0;
	*line = ft_strjoin(*line, buffer);
	move(buffer, newline);
}

int	check_buffer_plz(char *buffer, char **line)
{
	if (((int)find(buffer, '\n')) != -1)
	{
		from_buffer(buffer, line);
		return (1);
	}
	*line = ft_strjoin(*line, buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			size;
	char		*line;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	line = 0;
	if (check_buffer_plz(buffer, &line))
		return (line);
	while (1)
	{
		ft_memset(buffer, 0, BUFFER_SIZE);
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		if (size == 0)
			return (end_of_file(&line));
		buffer[size] = 0;
		if (((int)find(buffer, '\n')) != -1)
		{
			from_buffer(buffer, &line);
			return (line);
		}
		else
			line = ft_strjoin(line, buffer);
	}
}
