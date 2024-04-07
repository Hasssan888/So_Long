#include "so_long.h"

int	hight_width(char *ptr, t_so_long *so_long)
{
	char	*str;

	so_long->fd = open(ptr, O_RDONLY);
	so_long->count = 0;
	str = get_next_line(so_long->fd);
	while (str != NULL)
	{
		so_long->count++;
		str = get_next_line(so_long->fd);
	}
	close(so_long->fd);
	return (so_long->count);
}

int	widht_map(t_so_long *so_long)
{
	so_long->line = get_next_line(so_long->fd);
	so_long->i = str_len_map(so_long->line);
	so_long->line = get_next_line(so_long->fd);
	while (so_long->line != NULL)
	{
		so_long->j = str_len_map(so_long->line);
		// printf("lenght the j is -> %d\n", so_long->j);
		if (so_long->i != so_long->j)
		{
			printf("Map invalid\n");
			exit(1);
		}
		so_long->line = get_next_line(so_long->fd);
	}
	close(so_long->fd);
	return (so_long->i);
}

char	**cpy_map(char *ptr, t_so_long *so_long)
{
	so_long->fd = open(ptr, O_RDONLY);
	so_long->line = get_next_line(so_long->fd);
	so_long->i = 0;
	so_long->map = malloc(sizeof(char *) * (so_long->hight_map + 1));
	while (so_long->i < so_long->hight_map)
	{
		so_long->map[so_long->i] = malloc(sizeof(char) * (so_long->width_map
					+ 2));
		so_long->i++;
	}
	so_long->j = 0;
	while (so_long->line != NULL)
	{
		ft_strcpy(so_long->map[so_long->j], so_long->line);
		so_long->j++;
		so_long->line = get_next_line(so_long->fd);
	}
	so_long->map[so_long->j] = NULL;
	close(so_long->fd);
	return (so_long->map);
}

int	check_map(t_so_long *maps)
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

int	count_C_E_P(t_so_long *maps)
{
	maps->i = 0;
	maps->count_C = 0;
	maps->count_E = 0;
	maps->count_P = 0;
	while (maps->i < maps->hight_map)
	{
		maps->j = 0;
		while (maps->j < maps->width_map)
		{
			if (maps->map[maps->i][maps->j] == 'C')
				maps->count_C++;
			if (maps->map[maps->i][maps->j] == 'E')
				maps->count_E++;
			if (maps->map[maps->i][maps->j] == 'P')
				maps->count_P++;
			maps->j++;
		}
		maps->i++;
	}
	printf("C = %d, E = %d, P = %d\n", maps->count_C, maps->count_E,
		maps->count_P);
	if (maps->count_C >= 1 && maps->count_E == 1 && maps->count_P == 1)
		return (1);
	return (0);
}