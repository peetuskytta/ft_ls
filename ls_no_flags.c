/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:03:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 14:16:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_ls(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		if (to_print[i].f_name[0] != '.')
			ft_putendl(to_print[i].f_name);
		i++;
	}
}

void	only_ls(t_data *arr_of_s)
{
	arr_of_s = list_files_and_directories(".", 0, 0);
	print_ls(arr_of_s, 0);
}