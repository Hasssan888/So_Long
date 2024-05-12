/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:06:02 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/10 15:18:52 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	images(t_so_long *so_long)
{
	so_long->enemy_ptr_1 = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/enemy_fr_1.xpm", &so_long->width, &so_long->height);
	so_long->enemy_ptr_6 = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/enemy_fr_6.xpm", &so_long->width, &so_long->height);
	so_long->enemy_ptr_8 = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/enemy_fr_8.xpm", &so_long->width, &so_long->height);
	so_long->enemy_ptr_15 = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/enemy_fr_15.xpm", &so_long->width,
			&so_long->height);
	so_long->enemy_ptr_16 = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/enemy_fr_16.xpm", &so_long->width,
			&so_long->height);
	so_long->player_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/plyaer3.xpm", &so_long->width, &so_long->height);
	so_long->player_r_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/luffy_ri.xpm", &so_long->width, &so_long->height);
	so_long->player_l_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/luffy_left.xpm", &so_long->width, &so_long->height);
	so_long->door_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./textures/xpm/AnyConv.com__doorblu.xpm", &so_long->width,
			&so_long->height);
}

void	check_images(t_so_long *so_long)
{
	if (so_long->player_ptr == NULL || so_long->player_r_ptr == NULL
		|| so_long->player_l_ptr == NULL || so_long->door_ptr == NULL
		|| so_long->door_over_ptr == NULL || so_long->wall_ptr == NULL
		|| so_long->floor_ptr == NULL || so_long->collec == NULL
		|| so_long->enemy_ptr_1 == NULL || so_long->enemy_ptr_6 == NULL
		|| so_long->enemy_ptr_8 == NULL || so_long->enemy_ptr_15 == NULL
		|| so_long->enemy_ptr_16 == NULL)
	{
		printf("Error\nInvalidImage");
		ft_free(so_long);
	}
}

void	print_fr_enemy(t_so_long *so_long)
{
	if (so_long->k < 4000)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_1, so_long->j * SIZE, so_long->i * SIZE);
	else if (so_long->k < 16000)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_6, so_long->j * SIZE, so_long->i * SIZE);
	else if (so_long->k < 32000)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_8, so_long->j * SIZE, so_long->i * SIZE);
	else if (so_long->k < 64000)
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_15, so_long->j * SIZE, so_long->i * SIZE);
	else if (so_long->k < 74000)
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->enemy_ptr_16, so_long->j * SIZE, so_long->i * SIZE);
		so_long->k = 0;
	}
	so_long->k++;
}

int	animation(t_so_long *so_long)
{
	so_long->i = 0;
	while (so_long->i < so_long->hight_map)
	{
		so_long->j = 0;
		while (so_long->j < so_long->width_map)
		{
			if (so_long->map[so_long->i][so_long->j] == 'M')
				print_fr_enemy(so_long);
			so_long->j++;
		}
		so_long->i++;
	}
	return (0);
}
