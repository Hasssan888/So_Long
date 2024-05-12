/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:28:48 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/10 15:18:41 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_image(t_so_long *so_long)
{
	if (so_long->player_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->player_ptr);
	if (so_long->player_r_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->player_r_ptr);
	if (so_long->player_l_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->player_l_ptr);
	if (so_long->door_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->door_ptr);
	if (so_long->door_over_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->door_over_ptr);
	if (so_long->wall_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->wall_ptr);
	if (so_long->floor_ptr != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->floor_ptr);
	if (so_long->collec != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->collec);
	if (so_long->enemy_ptr_1 != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->enemy_ptr_1);
}

void	ft_free(t_so_long *so_long)
{
	destroy_image(so_long);
	if (so_long->enemy_ptr_6 != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->enemy_ptr_6);
	if (so_long->enemy_ptr_8 != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->enemy_ptr_8);
	if (so_long->enemy_ptr_15 != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->enemy_ptr_15);
	if (so_long->enemy_ptr_16 != NULL)
		mlx_destroy_image(so_long->mlx_ptr, so_long->enemy_ptr_16);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free_map(so_long);
	free(so_long->mlx_ptr);
	exit(0);
}

void	free_map(t_so_long *so_long)
{
	int	i;

	i = -1;
	while (++i < so_long->hight_map)
	{
		free(so_long->map[i]);
		free(so_long->map_2[i]);
	}
	free(so_long->map_2);
	free(so_long->map);
}

int	check_col(t_so_long *maps, int x, int y)
{
	if (maps->map[x][y] == 'C')
	{
		maps->collect_found++;
		maps->map[x][y] = '0';
	}
	if (maps->collect_found == maps->count_col)
	{
		mlx_put_image_to_window(maps->mlx_ptr, maps->win_ptr,
			maps->door_over_ptr, SIZE * maps->door_y, SIZE * maps->door_x);
		if (maps->map[x][y] == 'E')
		{
			print_moves(maps);
			ft_putstr_fd("You won\n", 1);
			ft_free(maps);
		}
	}
	if (maps->map[x][y] == 'M')
	{
		ft_putstr_fd("You lost\n", 1);
		print_moves(maps);
		ft_free(maps);
	}
	if (maps->map[x][y] != 'E')
		return (1);
	return (0);
}

void	print_moves(t_so_long *data)
{
	char	*c;

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_ptr, 1
		* 64, 0);
	c = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 20, 0xFFFFFF, "Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 100, 20, 0xFFFFFF, c);
	free(c);
	data->moves++;
}
