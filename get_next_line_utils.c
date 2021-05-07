#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

void	*ft_newstr(size_t count)
{
	void	*ptr;
	unsigned char	*help;

	if (!count)
		count = 1;
	ptr = malloc(count);
	help = (unsigned char *) ptr;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	iter;
	char	*res;

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
