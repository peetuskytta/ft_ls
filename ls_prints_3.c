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

/*void	print_t_mod(int time)
{
	space_after_nbr(time);
}
*/
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