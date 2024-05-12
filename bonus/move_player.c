/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:24:49 by hbakrim           #+#    #+#             */
/*   Updated: 2024/04/30 10:24:51 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	move_up(t_so_long *so_long)
{
	print_moves(so_long);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
	so_long->player_x--;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->player_ptr, SIZE * so_long->player_y, SIZE
		* so_long->player_x);
}

void	move_down(t_so_long *so_long)
{
	print_moves(so_long);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
	so_long->player_x++;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->player_ptr, SIZE * so_long->player_y, SIZE
		* so_long->player_x);
}

void	move_left(t_so_long *so_long)
{
	print_moves(so_long);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
	so_long->player_y--;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->player_l_ptr, SIZE * so_long->player_y, SIZE
		* so_long->player_x);
}

void	move_right(t_so_long *so_long)
{
	print_moves(so_long);
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
	so_long->player_y++;
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
		so_long->player_r_ptr, SIZE * so_long->player_y, SIZE
		* so_long->player_x);
}

int	move_player(int keycode, t_so_long *so_long)
{
	if (keycode == ESP || keycode == Q)
	{
		ft_free(so_long);
		exit(0);
	}
	if ((keycode == UP || keycode == W) && so_long->player_x - 1 > 0
		&& so_long->map[so_long->player_x - 1][so_long->player_y] != '1'
		&& check_col(so_long, so_long->player_x - 1, so_long->player_y))
		move_up(so_long);
	if ((keycode == DOWN || keycode == S) && so_long->player_x
		+ 1 < so_long->hight_map
		&& so_long->map[so_long->player_x + 1][so_long->player_y] != '1'
		&& check_col(so_long, so_long->player_x + 1, so_long->player_y))
		move_down(so_long);
	if ((keycode == LEFT || keycode == A) && so_long->player_y - 1 > 0
		&& so_long->map[so_long->player_x][so_long->player_y - 1] != '1'
		&& check_col(so_long, so_long->player_x, so_long->player_y - 1))
		move_left(so_long);
	if ((keycode == RIGHT || keycode == D) && so_long->player_y
		+ 1 < so_long->width_map
		&& so_long->map[so_long->player_x][so_long->player_y + 1] != '1'
		&& check_col(so_long, so_long->player_x, so_long->player_y + 1))
		move_right(so_long);
	return (0);
}
