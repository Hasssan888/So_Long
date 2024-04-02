#ifndef SO_LONG_H
#define SO_LONG_H

#include "./minilibx-linux/mlx.h"
#include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

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


#endif