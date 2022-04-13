/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:54 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/13 08:07:53 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This print_ls_a function prints all the files/directories/links etc in the
** current directory. TO-DO: ADD FLAG DETECTION AND CALLS ACCORDINGLY.
**
*/
static void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putendl(to_print[i].f_name);
		i++;
	}
}

void	ls_with_flags(t_data *arr_of_s, char **string)
{
	if (ft_strcmp(string[2], "-a") == 0)
		arr_of_s->flags[0] = 1;
	arr_of_s = list_files_and_directories(".", arr_of_s, 0, 0);
	print_ls_a(arr_of_s, 0);
}