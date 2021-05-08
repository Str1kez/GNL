#include <stdlib.h>

size_t ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

void *ft_newstr(size_t count)
{
	void *ptr;
	unsigned char *help;

	if (!count)
		count = 1;
	ptr = malloc(count);
	help = (unsigned char *)ptr;
	if (ptr)
	{
		while (count)
		{
			*help = 0;
			help++;
			count--;
		}
		return (ptr);
	}
	return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t iter;
	char *res;

	if (!s1 || !s2)
		return (NULL);
	iter = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	while (iter < s1_len)
	{
		res[iter] = s1[iter];
		iter++;
	}
	while (iter < s1_len + s2_len)
	{
		res[iter] = s2[iter - s1_len];
		iter++;
	}
	res[s1_len + s2_len] = '\0';
	return (res);
}

char *ft_strdup(const char *s1)
{
	char *res;
	size_t s1_len;
	size_t iter;

	s1_len = 0;
	while (s1[s1_len] != '\n' && s1[s1_len] != '\0')
		s1_len++;
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
