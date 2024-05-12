/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:25:10 by hbakrim           #+#    #+#             */
/*   Updated: 2024/04/30 10:25:12 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	coordinates_player(t_so_long *so_long)
{
	so_long->i = 0;
	while (so_long->i < so_long->hight_map)
	{
		so_long->j = 0;
		while (so_long->j < so_long->width_map)
		{
			if (so_long->map[so_long->i][so_long->j] == 'P')
			{
				so_long->player_x = so_long->i;
				so_long->player_y = so_long->j;
				return ;
			}
			so_long->j++;
		}
		so_long->i++;
	}
}

void	init_map(t_so_long *so_long)
{
	so_long->height = 64;
	so_long->width = 64;
	images(so_long);
	so_long->door_over_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/AnyConv.com__doorbluover.xpm", &so_long->width,
			&so_long->height);
	so_long->wall_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/wallblue.xpm", &so_long->width, &so_long->height);
	so_long->floor_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/floor1.xpm", &so_long->width, &so_long->height);
	so_long->collec = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/meat.xpm", &so_long->width, &so_long->height);
	check_images(so_long);
}

void	print_imag(t_so_long *so_long)
{
	if (so_long->map[so_long->i][so_long->j] == '1')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->wall_ptr, SIZE * so_long->j, SIZE * so_long->i);
	if (so_long->map[so_long->i][so_long->j] == '0')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->floor_ptr, SIZE * so_long->j, SIZE * so_long->i);
	if (so_long->map[so_long->i][so_long->j] == 'P')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->player_ptr, SIZE * so_long->j, SIZE * so_long->i);
	if (so_long->map[so_long->i][so_long->j] == 'E')
	{
		so_long->door_x = so_long->i;
		so_long->door_y = so_long->j;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->door_ptr, SIZE * so_long->j, SIZE * so_long->i);
	}
	if (so_long->map[so_long->i][so_long->j] == 'C')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->collec, SIZE * so_long->j, SIZE * so_long->i);
	if (so_long->map[so_long->i][so_long->j] == 'M')
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_1, SIZE * so_long->j, SIZE * so_long->i);
}

void	print_map(t_so_long *so_long)
{
	so_long->i = 0;
	init_map(so_long);
	while (so_long->i < so_long->hight_map)
	{
		so_long->j = 0;
		while (so_long->j < so_long->width_map)
		{
			print_imag(so_long);
			so_long->j += 1;
		}
		so_long->i += 1;
	}
}
