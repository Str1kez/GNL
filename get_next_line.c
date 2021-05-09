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

char *ft_strdup(const char *s1)
{
	char *res;
	size_t s1_len;
	size_t iter;

	s1_len = ft_strlen(s1);
	res = (char *)malloc(s1_len + 1);
	if (res)
	{
		iter = 0;
		while (iter < s1_len)
		{
			res[iter] = s1[iter];
			iter++;
		}
		res[iter] = '\0';
		return (res);
	}
	return (NULL);
}

static void str_clean(char **str)
{
	if (*str)
	{
		free(ft_memset(*str, 0, ft_strlen(*str)));
		*str = NULL;
	}
}

static int check(size_t read, char **res, char **line)
{
	char *temp;
	char *is_endl;

	if (read == 0)
	{
		*line = ft_strdup(*res);
		str_clean(res);
		return (0);
	}
	is_endl = ft_strchr(*res, '\n');
	if (is_endl && read > 0)
	{
		temp = ft_strdup_endl(*res, is_endl);
		*line = temp;
		// ? Не теряется ли здесь is_endl?
		str_clean(res);
		*res = ft_strdup(is_endl + 1);
		return (1);
	}
	str_clean(res);
	return (-1);
}

int get_next_line(int fd, char **line)
{
	size_t r;
	char buf[BUFFER_SIZE + 1];
	static char *res = NULL;
	char *temp;

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	if (!res)
		res = ft_memset((char *)malloc(1), 0, 1);
	r = 1;
	if (!ft_strchr(res, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		while (r > 0)
		{
			buf[r] = '\0';
			temp = ft_strjoin(res, buf);
			str_clean(&res);
			res = temp;
			if (ft_strchr(res, '\n'))
				break;
			r = read(fd, buf, BUFFER_SIZE);
		}
	}
	return (check(r, &res, line));
}

int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		exit(1);
	// printf("%d\n", get_next_line(fd, &line));
	get_next_line(fd, &line);
	printf("%s\n", line);
	str_clean(&line);
	// printf("%d\n", get_next_line(fd, &line));
	get_next_line(fd, &line);
	printf("%s\n", line);
	str_clean(&line);
	// printf("%d\n", get_next_line(fd, &line));
	get_next_line(fd, &line);
	printf("%s\n", line);
	str_clean(&line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	str_clean(&line);
	close(fd);
	return (0);
}
