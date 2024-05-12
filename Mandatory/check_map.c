/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:23:00 by hbakrim           #+#    #+#             */
/*   Updated: 2024/04/30 10:28:24 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wallmap(t_so_long *maps)
{
	maps->i = 1;
	maps->j = 0;
	while (maps->j < maps->width_map)
	{
		if (maps->map[maps->hight_map - 1][maps->j] != '1'
			|| maps->map[0][maps->j] != '1')
			return (0);
		maps->j++;
	}
	while (maps->i < maps->hight_map - 1)
	{
		if (maps->map[maps->i][0] != '1' || maps->map[maps->i][maps->width_map
			- 1] != '1')
			return (0);
		maps->i++;
	}
	return (1);
}

void	declaration(t_so_long *maps)
{
	maps->i = 0;
	maps->count_col = 0;
	maps->count_exi = 0;
	maps->count_pla = 0;
}

int	count_col_exi_pla(t_so_long *maps)
{
	declaration(maps);
	while (maps->i < maps->hight_map)
	{
		maps->j = 0;
		while (maps->j < maps->width_map)
		{
			if (maps->map[maps->i][maps->j] != '1'
				&& maps->map[maps->i][maps->j] != '0'
				&& maps->map[maps->i][maps->j] != 'E'
				&& maps->map[maps->i][maps->j] != 'C'
				&& maps->map[maps->i][maps->j] != 'P')
				return (0);
			if (maps->map[maps->i][maps->j] == 'C')
				maps->count_col++;
			if (maps->map[maps->i][maps->j] == 'E')
				maps->count_exi++;
			if (maps->map[maps->i][maps->j] == 'P')
				maps->count_pla++;
			maps->j++;
		}
		maps->i++;
	}
	if (maps->count_col >= 1 && maps->count_exi == 1 && maps->count_pla == 1)
		return (1);
	return (0);
}

int	check_floo(t_so_long *data)
{
	flood_fill(data, data->player_x, data->player_y);
	data->i = 0;
	data->i = 0;
	while (data->i < data->hight_map)
	{
		data->j = 0;
		while (data->j < data->width_map)
		{
			if (data->map_2[data->i][data->j] == 'E'
				|| data->map_2[data->i][data->j] == 'C')
				return (0);
			data->j++;
		}
		data->i++;
	}
	return (1);
}
