#include "so_long.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len_s;
	char	*result;

	i = 0;
	len_s = ft_strlen(s);
	result = malloc(sizeof(char *) * len_s + 1);
	if (result == NULL)
		return (0);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char *s, char *buf)
{
	size_t	len;
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strdup(buf));
	if (!buf)
		return (0);
	len = ft_strlen(s) + ft_strlen(buf);
	result = (malloc(len * (sizeof(char *)) + 1));
	if (!result)
		return (NULL);
	while (s[j])
		result[i++] = s[j++];
	j = 0;
	while (buf[j])
		result[i++] = buf[j++];
	result[i] = '\0';
	free(s);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}