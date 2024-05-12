/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:23:54 by hbakrim           #+#    #+#             */
/*   Updated: 2024/04/30 10:23:56 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	hight_map(char *ptr, t_so_long *so_long)
{
	char	*str;

	so_long->fd = open(ptr, O_RDONLY);
	so_long->count = 0;
	str = get_next_line(so_long->fd);
	while (str != NULL)
	{
		so_long->count++;
		free(str);
		str = get_next_line(so_long->fd);
	}
	close(so_long->fd);
	return (so_long->count);
}

int	widht_map(t_so_long *so_long)
{
	so_long->line = get_next_line(so_long->fd);
	so_long->i = str_len_map(so_long->line);
	free(so_long->line);
	so_long->line = get_next_line(so_long->fd);
	while (so_long->line != NULL)
	{
		so_long->j = str_len_map(so_long->line);
		if (so_long->i != so_long->j)
		{
			free(so_long->line);
			ft_putstr_fd("Error\n", 1);
			ft_putstr_fd("Map invalid\n", 1);
			exit(1);
		}
		free(so_long->line);
		so_long->line = get_next_line(so_long->fd);
	}
	close(so_long->fd);
	return (so_long->i);
}

char	**cpy_map(char *ptr, t_so_long *so_long)
{
	so_long->fd = open(ptr, O_RDONLY);
	so_long->line = get_next_line(so_long->fd);
	so_long->i = 0;
	so_long->map = malloc(sizeof(char *) * (so_long->hight_map + 1));
	while (so_long->i < so_long->hight_map)
	{
		so_long->map[so_long->i] = malloc(sizeof(char) * (so_long->width_map
					+ 2));
		so_long->i++;
	}
	so_long->j = 0;
	while (so_long->line != NULL)
	{
		ft_strcpy(so_long->map[so_long->j], so_long->line);
		so_long->j++;
		free(so_long->line);
		so_long->line = get_next_line(so_long->fd);
	}
	so_long->map[so_long->j] = NULL;
	close(so_long->fd);
	return (so_long->map);
}

char	**cpy_map_2(char *ptr, t_so_long *so_long)
{
	so_long->fd = open(ptr, O_RDONLY);
	so_long->line = get_next_line(so_long->fd);
	so_long->i = 0;
	so_long->map_2 = malloc(sizeof(char *) * (so_long->hight_map + 1));
	while (so_long->i < so_long->hight_map)
	{
		so_long->map_2[so_long->i] = malloc(sizeof(char) * (so_long->width_map
					+ 2));
		so_long->i++;
	}
	so_long->j = 0;
	while (so_long->line != NULL)
	{
		ft_strcpy(so_long->map_2[so_long->j], so_long->line);
		so_long->j++;
		free(so_long->line);
		so_long->line = get_next_line(so_long->fd);
	}
	so_long->map_2[so_long->j] = NULL;
	close(so_long->fd);
	return (so_long->map_2);
}

void	flood_fill(t_so_long *data, int i, int j)
{
	if (data->map_2[i][j] != '0' && data->map_2[i][j] != 'C'
		&& data->map_2[i][j] != 'E' && data->map_2[i][j] != 'P'
		&& data->map_2[i][j] != 'M')
		return ;
	else if (data->map_2[i][j] == 'E' || data->map_2[i][j] == 'M')
	{
		data->map_2[i][j] = '+';
		return ;
	}
	data->map_2[i][j] = 'X';
	flood_fill(data, i + 1, j);
	flood_fill(data, i - 1, j);
	flood_fill(data, i, j + 1);
	flood_fill(data, i, j - 1);
}
