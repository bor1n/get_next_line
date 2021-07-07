#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include	"get_next_line.h"
int	main(void)
{
	int		fd;
	char	*i;
	//fd = open("/Users/wngan/school21/projects/get_next_line-project/get_nex_line1.1/gnlTester/files/multiple_nlx5", O_RDONLY);
	fd = open("/Users/avarys/CLionProjects/untitled1/file", O_RDONLY);
	printf("%d\n", fd);
	while ((i = get_next_line(fd)) != NULL)
	{
		printf("%s\n", i);
	}
	return (0);
}