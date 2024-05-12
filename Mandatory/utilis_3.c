/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:28:48 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/01 17:29:39 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(t_so_long *so_long)
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
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free_map(so_long);
	free(so_long->mlx_ptr);
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
	free(so_long->map);
	free(so_long->map_2);
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
			exit(0);
		}
	}
	if (maps->map[x][y] != 'E')
		return (1);
	return (0);
}

void	print_moves(t_so_long *data)
{
	data->moves++;
	ft_putstr_fd("moves:", 1);
	ft_putnbr(data->moves);
	ft_putchar('\n');
}
