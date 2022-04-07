/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/08 00:52:38 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_2ws(const char *str)
{
	ft_putstr("\033[0;32m");
	ft_putstr(str);
	ft_putstr("\033[0m");
	ft_putstr("  ");
}

void	print_ls(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		if (to_print[i].f_name[0] != '.')
			ft_putendl(to_print[i].f_name);
		i++;
	}
}

void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putendl(to_print[i].f_name);
		i++;
	}
}

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
