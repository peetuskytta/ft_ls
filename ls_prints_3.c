/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 07:52:39 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/27 07:52:39 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	space_after_nbr(int nbr)
{
	ft_putnbr(nbr);
	ft_putstr(" ");
}

void	space_after_str(char *str)
{
	ft_putstr(str);
	ft_putstr(" ");
}

void	print_t_mod(struct stat *stats)
{
	char	*str;
	char	**str2;
	int 	i;

	i = 0;
	str = ctime(&stats->st_mtime);
	str = ft_strtrim(str);
	str2 = ft_strsplit(str, ' ');
	space_after_str(str2[1]);
	if (ft_strlen(str2[2]) == 1)
		ft_putstr(" ");
	space_after_str(str2[2]);
	while (i < 5)
	{
		ft_putchar(str2[3][i++]);
	}
	ft_putstr(" ");
	ft_free_array(5, str2);
}

void	print_size(int size, int pad)
{
	// if link do something else
	int		len;

	len = pad - ft_nblen(size);
	while (len > 0)
	{
		ft_putchar(' ');
		len--;
	}
	space_after_nbr(size);
}