/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:42:19 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/07 13:42:32 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	exit_game(t_so_long *so_long)
{
	ft_free(so_long);
	exit(0);
	return (0);
}

void	check_map(t_so_long *so_long)
{
	if (check_wallmap(so_long) == 0 || count_col_exi_pla(so_long) == 0
		|| check_floo(so_long) == 0)
	{
		free_map(so_long);
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Map invalid\n", 1);
		exit(1);
	}
}

void	hight_widht(char **av, t_so_long *so_long)
{
	char	*ptr;

	ptr = av[1];
	so_long->fd = open(av[1], O_RDONLY);
	so_long->width_map = widht_map(so_long);
	so_long->hight_map = hight_map(ptr, so_long);
	so_long->map = cpy_map(ptr, so_long);
	so_long->map_2 = cpy_map_2(ptr, so_long);
}

void	check_arg_path(int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\narguments error", 1);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_so_long	so_long;

	check_arg_path(ac);
	if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber") != 0)
	{
		ft_putstr_fd("Error\nPath invalide\n", 1);
		exit(1);
	}
	so_long.collect_found = 0;
	hight_widht(av, &so_long);
	coordinates_player(&so_long);
	check_map(&so_long);
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.width_map * SIZE,
			so_long.hight_map * SIZE, "so_long");
	print_map(&so_long);
	so_long.moves = 0;
	print_moves(&so_long);
	mlx_hook(so_long.win_ptr, 02, 1L << 0, move_player, &so_long);
	mlx_hook(so_long.win_ptr, 17, 0, exit_game, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, animation, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
