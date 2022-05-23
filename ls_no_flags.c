/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:03:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/23 12:18:31 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ls(t_data *to_print, int i)
{
	while (i < to_print->count)
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

void	ls_w_flags(t_data *arr_of_s, char *name)
{
	arr_of_s = dir_stream(name, arr_of_s, 0, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);
	print_ls(arr_of_s, 0);
}
