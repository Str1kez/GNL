#include <stdio.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	get_next_line(int fd, char **line)
{
	size_t		r;
	char		buf[BUFFER_SIZE + 1];
	static char	*res = NULL;
	char		*temp;

	if (fd < 0)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	if (!res)
		res = ft_newstr(0);
	while (r > 0 && !ft_strchr(buf, '\0') && !ft_strchr(buf, '\n'))
	{
		buf[r] = '\0';
		temp = ft_strjoin(res, buf);
		free(res);
		res = temp;
		r = read(fd, buf, BUFFER_SIZE);
	}
	// TODO: вот тут нужны условия на вывод!!!
	return (0);
}

// int	main()
// {
// 	printf("%d\n", BUFFER_SIZE);
// 	return (0);
// }
