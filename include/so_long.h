/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:35:50 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/01 18:35:53 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define SIZE 64
# define ESP 65307
# define Q 113
# define A 97
# define W 119
# define S 115
# define D 100
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define LEFT 65361

typedef struct so_long
{
	int		fd;
	char	*line;
	int		count;
	int		i;
	int		j;
	int		width_map;
	int		hight_map;
	char	**map;
	char	**map_2;
	int		count_col;
	int		count_pla;
	int		count_exi;

	int		collect_found;
	void	*mlx_ptr;
	void	*win_ptr;

	void	*floor_ptr;
	void	*player_g_ptr;
	void	*player_r_ptr;
	void	*player_l_ptr;
	void	*player_ptr;
	void	*wall_ptr;
	void	*collec;
	void	*door_ptr;
	void	*door_over_ptr;
	int		player_x;
	int		player_y;
	int		door_x;
	int		door_y;

	int		moves;

	int		height;
	int		width;

}			t_so_long;

// ft_putnbr.
void		ft_putchar(char c);
void		ft_putnbr(int nb);

// get_next_line.c
char		*ft_read_creat(int fd, char *s);
char		*ft_extract_line(char *s);
char		*ft_return_s(char *s);
char		*get_next_line(int fd);

// get_next_line_utilis.c
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s, char *buf);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);

// utilis_1.c
char		*ft_strrchr(const char *str, int c);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strcpy(char *dest, char *src);
int			str_len_map(char *str);

// move_player.c
int			check_col(t_so_long *maps, int x, int y);
int			move_player(int keycode, t_so_long *so_long);
void		print_moves(t_so_long *data);
void		free_map(t_so_long *so_long);
void		ft_free(t_so_long *so_long);

// print_map.c
void		coordinates_player(t_so_long *so_long);
void		init_map(t_so_long *so_long);
void		print_map(t_so_long *so_long);

// utilis_2.c
int			hight_map(char *ptr, t_so_long *so_long);
int			widht_map(t_so_long *so_long);
char		**cpy_map(char *ptr, t_so_long *so_long);
char		**cpy_map_2(char *ptr, t_so_long *so_long);
void		flood_fill(t_so_long *data, int i, int j);

// check_map.c
int			check_wallmap(t_so_long *maps);
int			count_col_exi_pla(t_so_long *maps);
int			check_floo(t_so_long *data);
void		declaration(t_so_long *maps);
int			is_rectangle(t_so_long *data);

#endif
