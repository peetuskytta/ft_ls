/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 14:36:06 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*void	print_ls(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		if (to_print[i].f_name[0] != '.')
			ft_putendl(to_print[i].f_name);
		i++;
	}
}  MOVED TO ls_no_flags.c TO BE STATIC */

/*void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putendl(to_print[i].f_name);
		i++;
	}
} MOVED TO ls_with_a.c TO BE STATIC */

void	print_double(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putendl(str[i]);
		i++;
	}
}
