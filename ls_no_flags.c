/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:03:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/30 13:50:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ls(t_data *to_print, int i)
{
	while (i < to_print[1].count)
	{
		if (to_print[i].f_name[0] != '.')
		{
			ft_putstr(to_print[i].f_name);
			if (to_print->count >= i + 1)
				ft_putstr("  ");
		}
		i++;
	}
	ft_putendl("");
}

void	ls_w_flags(t_data *arr, char *name)
{
	arr = dir_stream(name, arr, 0, 0);
	print_ls(arr, 0);
}

void	ls_l_flags(t_data *arr, char *name)
{
	arr = dir_stream(name, arr, 0, 0);
	ft_putendl(arr[2].f_name);
	ft_putnbr_endl(arr->flags[0]);
	ft_putnbr_endl(arr->flags[1]);
	ft_putnbr_endl(arr->flags[2]);
	ft_putnbr_endl(arr->flags[3]);
	ft_putnbr_endl(arr->flags[4]);
	print_long(arr, 0);
}