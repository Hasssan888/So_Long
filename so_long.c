#include "so_long.h"

int	exit_game(t_so_long *so_long)
{
	(void)so_long;
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_so_long so_long;
	if (ac != 2)
		return (1);

	so_long.collect_found = 0;
	printf("comp = %d\n\n", ft_strcmp(ft_strrchr(av[1], '.'), ".ber"));
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber") == 0)
	{
		char *ptr;

		ptr = av[1];
		so_long.fd = open(av[1], O_RDONLY);
		so_long.width_map = widht_map(&so_long);
		so_long.hight_map = hight_width(ptr, &so_long);
		printf("width: %d\n", so_long.width_map);
		printf("hight: %d\n", so_long.hight_map);
		so_long.map = cpy_map(ptr, &so_long);
		so_long.i = 0;
		while (so_long.i < so_long.hight_map)
		{
			printf("map[%d] = %s", so_long.i, so_long.map[so_long.i]);
			so_long.i++;
		}
		printf("\n");
		if (check_map(&so_long) == 1 && count_C_E_P(&so_long) == 1)
			printf("Map valid\n");
		else
		{
			printf("Map invalid\n");
			exit(1);
		}
	}
	else
	{
		ft_putstr_fd("Path invalide\n", 2);
		exit(1);
	}
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.width_map * SIZE,
			so_long.hight_map * SIZE, "so_long");
	Coordinates_player(&so_long);
	print_map(&so_long);
	mlx_hook(so_long.win_ptr, 02, 1L << 0, move_player, &so_long);
	mlx_hook(so_long.win_ptr, 17, 0, exit_game, &so_long);
	mlx_loop(so_long.mlx_ptr);
}