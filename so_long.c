#include "so_long.h"

int str_len_map(char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] != '\n')
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
    so_long->map = malloc(sizeof(char *) * (so_long->hight_map));
    while (so_long->i < so_long->hight_map)
    {
        so_long->map[so_long->i] = malloc(sizeof(char) * (so_long->width_map + 1));
        so_long->i++;
    }
    so_long->j = 0;
    while (so_long->line != NULL)
    {
        ft_strcpy(so_long->map[so_long->j], so_long->line);
        so_long->j++;
        so_long->line = get_next_line(so_long->fd);            
    }
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

int main(int ac, char **av)
{
    t_so_long so_long;
    (void)ac;

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
}