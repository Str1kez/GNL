#include <stdio.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	get_next_line(int fd, char **line)
{
	size_t	r;

	if (fd < 0)
		return (-1);
	r = read(fd, *line, BUFFER_SIZE);
	while (r > 0)
	{

	}
	return (0);
}

// int	main()
// {
// 	printf("%d\n", BUFFER_SIZE);
// 	return (0);
// }
