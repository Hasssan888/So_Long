#include "so_long.h"

void	Coordinates_player(t_so_long *so_long)
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
	int	height;
	int	width;

	height = 64;
	width = 64;
	so_long->player_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/player1.xpm", &width, &height);
	so_long->door_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/door_exit_1.xpm", &width, &height);
	so_long->door_over_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/door.xpm", &width, &height);
	so_long->wall_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/wall.xpm", &width, &height);
	so_long->floor_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/fool1712254752.xpm", &width, &height);
	so_long->collec = mlx_xpm_file_to_image(so_long->mlx_ptr,
			"./image/xpm/dolr1712254751.xpm", &width, &height);
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
			printf("%d %d\n", so_long->i, so_long->j);
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
			so_long->j += 1;
		}
		so_long->i += 1;
	}
}