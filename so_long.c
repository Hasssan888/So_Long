#include "so_long.h"

int hight_map(int fd)
{
    int count = 0;
    char *line = get_next_line(fd);
    while (line != NULL)
    {
        line = get_next_line(fd);
        count++;
    }
    close(fd);
    return (count);
}

int ft_strlen_width(int fd)
{
    char *line;
    //int   i;
    
    line = get_next_line(fd);
    printf("%s", line);
    // close(fd);
    // i = 0;
    // while (line[i] != '\n' && line[i] != '\0')
    //     i++;
    // return(i);
    return(0);
}

int main(int ac, char **av)
{
    (void)ac;
    int count = 0;
    int width;
    if (ft_strcmp(ft_strrchr(av[1], '.'), ".ber") == 0)
    {
        int fd = open(av[1], O_RDONLY, 0644);
        count = hight_map(fd);
        width = ft_strlen_width(fd);
        printf("%d", width);
    }
    else
        ft_putstr_fd("Path invalide\n", 2);
}