/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:26:49 by hbakrim           #+#    #+#             */
/*   Updated: 2024/04/30 10:26:52 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL || fd < 0)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	str_len_map(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}
