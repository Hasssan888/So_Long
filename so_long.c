#include "so_long.h"

int str_len_map(char *str)
{
    int i = 0;
    while (str != NULL && str[i] != '\0' && str[i] != '\n')
        i++;
    return(i);
}
int hight_width(char *ptr, t_so_long *so_long)
{
    char *str;
    
    so_long->fd = open(ptr, O_RDONLY);
    so_long->count = 0;
    str = get_next_line(so_long->fd);
    while (str != NULL)
    {
        so_long->count++;
        str = get_next_line(so_long->fd);
    }
    close(so_long->fd);
    return(so_long->count);
}
int widht_map(t_so_long *so_long)
{
    so_long->line = get_next_line(so_long->fd);
    so_long->i = str_len_map(so_long->line);
    so_long->line = get_next_line(so_long->fd);
    while (so_long->line != NULL)
    {
        so_long->j = str_len_map(so_long->line);
        //printf("lenght the j is -> %d\n", so_long->j);
        if (so_long->i != so_long->j)
        {
            printf("Map invalid\n");
            exit(1);
        }
        so_long->line = get_next_line(so_long->fd);
    }
    close(so_long->fd);
    return(so_long->i);
}

char    **cpy_map(char *ptr, t_so_long *so_long)
{
    so_long->fd = open(ptr, O_RDONLY);
    so_long->line = get_next_line(so_long->fd);
    so_long->i = 0;
    so_long->map = malloc(sizeof(char *) * (so_long->hight_map + 1));
    while (so_long->i < so_long->hight_map)
    {
        so_long->map[so_long->i] = malloc(sizeof(char) * (so_long->width_map + 2));
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
    return(so_long->map);
}

int     count_C_E_P(t_so_long *maps)
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
    printf("C = %d, E = %d, P = %d\n", maps->count_C, maps->count_E, maps->count_P);
    if (maps->count_C >= 1 && maps->count_E == 1 && maps->count_P == 1)
        return(1);
    return(0);
}

int     check_map(t_so_long *maps)
{
    maps->i = 1;
    maps->j = 0;
    while (maps->j < maps->width_map)
    {
        if (maps->map[maps->hight_map - 1][maps->j] != '1' || maps->map[0][maps->j] != '1')
            return(0);
        maps->j++;
    }
    while (maps->i < maps->hight_map - 1)
    {
        if (maps->map[maps->i][0] != '1' || maps->map[maps->i][maps->width_map - 1] != '1')
            return(0);
        maps->i++;
    }
    return(1);
}

void    Coordinates_player(t_so_long *so_long)
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
                return;
            }
            so_long->j++;
        }
        so_long->i++;
    }
}

int    check_C(t_so_long *maps)
{
    maps->i = 0;
    maps->count = 0;
    while (maps->i < maps->hight_map)
    {
        maps->j = 0;
        while (maps->j < maps->width_map)
        {
            if (maps->map[maps->player_x][maps->player_y] == 'C')
                maps->count++;
            maps->j++;
        }
        maps->i++;
    }
    //if (maps->count_C == maps->count)
    return(1);
}

int move_player(int keycode, t_so_long *so_long)
{
    printf("keycode == %d\n", keycode);
    (void)so_long;
    if (keycode == ESP || keycode == Q)
    {
        exit(0);
    }
    if (keycode == UP && so_long->player_x - 1 > 0 && so_long->map[so_long->player_x - 1][so_long->player_y] != '1' && check_C(so_long))
    {
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
        so_long->player_x -= 1;
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->player_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
    }
    if (keycode == DOWN && so_long->player_x + 1 < so_long->hight_map && so_long->map[so_long->player_x + 1][so_long->player_y] != '1' && check_C(so_long))
    {
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
        so_long->player_x += 1;
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->player_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
    }
    if (keycode == LEFT && so_long->player_y - 1 > 0 && so_long->map[so_long->player_x][so_long->player_y - 1] != '1')
    {
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
        so_long->player_y -= 1;
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->player_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
    }
    if (keycode == RIGHT && so_long->player_y + 1 < so_long->width_map && so_long->map[so_long->player_x][so_long->player_y + 1] != '1' && check_C(so_long))
    {
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->floor_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
        so_long->player_y += 1;
        mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->player_ptr, SIZE * so_long->player_y, SIZE * so_long->player_x);
    }
    return 0;
}

void init_map(t_so_long *so_long)
{
    int height = 64;
    int width = 64;
    so_long->player_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./image/xpm/player1.xpm", &width, &height);
    so_long->door_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./image/xpm/door.xpm", &width, &height);
    so_long->wall_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./image/xpm/wall.xpm", &width, &height);
    so_long->floor_ptr = mlx_xpm_file_to_image(so_long->mlx_ptr, "./image/xpm/fool1712254752.xpm", &width, &height);
    so_long->collec = mlx_xpm_file_to_image(so_long->mlx_ptr, "./image/xpm/dolr1712254751.xpm", &width, &height);
}

void print_map(t_so_long *so_long)
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
                mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->wall_ptr, SIZE * so_long->j, SIZE * so_long->i);
            if (so_long->map[so_long->i][so_long->j] == '0')
                mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->floor_ptr, SIZE * so_long->j, SIZE * so_long->i);
            if (so_long->map[so_long->i][so_long->j] == 'P')
                mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->player_ptr, SIZE * so_long->j, SIZE * so_long->i);
            if (so_long->map[so_long->i][so_long->j] == 'E')
                mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->door_ptr, SIZE * so_long->j, SIZE * so_long->i);
            if (so_long->map[so_long->i][so_long->j] == 'C')
                mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, so_long->collec, SIZE * so_long->j, SIZE * so_long->i);
            so_long->j += 1;
        }
        so_long->i += 1;
    }
    
}
int exit_game(t_so_long *so_long)
{
    (void)so_long;
    exit(0);
    return (0);
}

int main(int ac, char **av)
{
    t_so_long so_long;
    if (ac != 2)
        return (1);

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
            printf("Map invalid\n");
        
    }
    else
        ft_putstr_fd("Path invalide\n", 2);
    so_long.mlx_ptr = mlx_init();
    so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.width_map * SIZE, so_long.hight_map * SIZE, "so_long");
    Coordinates_player(&so_long);
    print_map(&so_long);
    mlx_hook(so_long.win_ptr, 02, 1L<<0, move_player, &so_long);
    mlx_hook(so_long.win_ptr, 17, 0, exit_game, &so_long);
    mlx_loop(so_long.mlx_ptr);
}