#include <stdio.h>
#include <fcntl.h>	   /* open() and O_XXX flags */
#include <sys/stat.h>  /* S_IXXX flags */
#include <sys/types.h> /* mode_t */
#include <unistd.h>	   /* close() */
#include <stdlib.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

static int check(size_t read, char *buf, char *res, char **line)
{
	char *copy_buf;

	if (read <= 0)
	{
		*line = res;
		return (0);
	}
	if (ft_strchr(buf, '\n'))
	{
		copy_buf = ft_strdup(buf);
		res = ft_strjoin(res, copy_buf);
		*line = res;
		free(copy_buf);
		return (1);
	}
	free(res);
	return (-1);
}

int get_next_line(int fd, char **line)
{
	size_t r;
	char buf[BUFFER_SIZE + 1];
	static char *res = NULL;
	char *temp;

	if (fd < 0)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	if (!res)
		res = ft_newstr(0);
	while (r > 0 && !ft_strchr(buf, '\n'))
	{
		buf[r] = '\0';
		temp = ft_strjoin(res, buf);
		free(res);
		res = temp;
		r = read(fd, buf, BUFFER_SIZE);
	}
	return (check(r, buf, res, line));
}

int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		exit(1);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
