/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:06:22 by hbakrim           #+#    #+#             */
/*   Updated: 2024/05/06 16:06:28 by hbakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	len_n(int nb)
{
	int	l;

	l = 0;
	if (nb <= 0)
		l++;
	while (nb)
	{
		nb /= 10;
		l++;
	}
	return (l);
}

static char	*zero(char *r)
{
	r[0] = '0';
	return (r);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		len;
	long	nbr;

	nbr = (long)n;
	len = len_n(nbr);
	r = malloc(sizeof(char) * (len + 1));
	if (r == NULL)
		return (NULL);
	r[len] = '\0';
	if (nbr == 0)
		return (zero(r));
	else if (nbr < 0)
	{
		r[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		r[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (r);
}

void	declaration(t_so_long *maps)
{
	maps->i = 0;
	maps->count_col = 0;
	maps->count_exi = 0;
	maps->count_pla = 0;
}

void	scop(t_so_long *maps)
{
	if (maps->map[maps->i][maps->j] == 'C')
		maps->count_col++;
	if (maps->map[maps->i][maps->j] == 'E')
		maps->count_exi++;
	if (maps->map[maps->i][maps->j] == 'P')
		maps->count_pla++;
	if (maps->map[maps->i][maps->j] == 'M')
		maps->count_enm++;
}
