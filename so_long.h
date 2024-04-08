#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
#include "./minilibx-linux/mlx.h"
//#include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#define SIZE 64
#define ESP 65307
#define Q 113
#define A 97
#define W 119
#define S 115
#define D 100
#define UP 65362
#define RIGHT 65363
#define DOWN 65364
#define LEFT 65361





typedef     struct so_long
{
    int fd;
    char *line;
    int count;
    int i;
    int j;
    int width_map;
    int hight_map;
    char **map;
    int count_C;
    int count_P;
    int count_E;

    int collect_found;
    void *mlx_ptr;
    void *win_ptr;

    void *floor_ptr;
    void *player_ptr;
    void *wall_ptr;
    void  *collec;
    void *door_ptr;
    void *door_over_ptr;
    int player_x;
    int player_y;
    int door_x;
    int door_y;

} t_so_long;


//get_next_line.c
char	*ft_read_creat(int fd, char *s);
char	*ft_extract_line(char *s);
char	*ft_return_s(char *s);
char	*get_next_line(int fd);

//get_next_line_utilis.c
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s, char *buf);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

//utilis_1.c
char	*ft_strrchr(const char *str, int c);
int	    ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dest, char *src);
int     str_len_map(char *str);

// move_player.c
int    check_C(t_so_long *maps, int x, int y);
int move_player(int keycode, t_so_long *so_long);

// print_map.c
void    Coordinates_player(t_so_long *so_long);
void    init_map(t_so_long *so_long);
void    print_map(t_so_long *so_long);

// check_map.c
int     hight_width(char *ptr, t_so_long *so_long);
int     widht_map(t_so_long *so_long);
char    **cpy_map(char *ptr, t_so_long *so_long);
int     check_map(t_so_long *maps);
int     count_C_E_P(t_so_long *maps);

#endif