#include "so_long.h"

int	check_C(t_so_long *maps, int x, int y)
{
	if (maps->map[maps->player_x][maps->player_y] == 'C')
	{
		maps->map[maps->player_x][maps->player_y] = '0';
		maps->collect_found += 1;
	}
	printf("%d %d\n", maps->collect_found, maps->count_C);
	if (maps->collect_found == maps->count_C)
		mlx_put_image_to_window(maps->mlx_ptr, maps->win_ptr,
			maps->door_over_ptr, SIZE * maps->door_y, SIZE * maps->door_x);
	if (maps->map[x][y] == 'E')
		exit(0);
	if (maps->map[x][y] != 'E')
		return (1);
	return (0);
}

int	move_player(int keycode, t_so_long *so_long)
{
	printf("keycode == %d\n", keycode);
	//(void)so_long;
	if (keycode == ESP || keycode == Q)
		exit(0);
	if (keycode == UP && so_long->player_x - 1 > 0
		&& so_long->map[so_long->player_x - 1][so_long->player_y] != '1'
		&& check_C(so_long, so_long->player_x - 1, so_long->player_y))
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->floor_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
		so_long->player_x -= 1;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->player_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
	}
	if (keycode == DOWN && so_long->player_x + 1 < so_long->hight_map
		&& so_long->map[so_long->player_x + 1][so_long->player_y] != '1'
		&& check_C(so_long, so_long->player_x + 1, so_long->player_y))
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->floor_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
		so_long->player_x += 1;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->player_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
	}
	if (keycode == LEFT && so_long->player_y - 1 > 0
		&& so_long->map[so_long->player_x][so_long->player_y - 1] != '1'
		&& check_C(so_long, so_long->player_x, so_long->player_y - 1))
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->floor_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
		so_long->player_y -= 1;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->player_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
	}
	if (keycode == RIGHT && so_long->player_y + 1 < so_long->width_map
		&& so_long->map[so_long->player_x][so_long->player_y + 1] != '1'
		&& check_C(so_long, so_long->player_x, so_long->player_y + 1))
	{
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->floor_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
		so_long->player_y += 1;
		mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr,
			so_long->player_ptr, SIZE * so_long->player_y, SIZE
			* so_long->player_x);
	}
	return (0);
}