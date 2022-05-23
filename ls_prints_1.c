/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/23 13:57:13 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	print_dir_access_err(char *name, int arg_count)
{
	if (arg_count > 1)
		print_filename(name, 1);
	ft_putstr("ls: ");
	ft_putstr(name);
	error_prints(1, ": Permissions denied");
	ft_putendl("");
}

void	print_filename(char *name, int id)
{
	if (id == 1)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	if (id == 0)
	{
		ft_putstr(name);
		ft_putstr("  ");
	}
}

void	print_nonexist(t_data *to_print, int i)
{
	while (to_print->list[i] != NULL)
	{
		if (stat(to_print->list[i], &to_print->info) != 0)
		{
			error_prints(6, to_print->list[i]);
		}
		i++;
	}
}

void	print_exists(t_data *to_print, int i)
{
	int	print;

	print = 0;
	while (to_print->list[i] != NULL)
	{
		if (stat(to_print->list[i], &to_print->info) == 0 && \
			to_print->info.st_mode & S_IFREG)
		{
			ft_putstr(to_print->list[i]);
			ft_putstr("  ");
			i++;
			print = 1;
		}
		else
			i++;
	}
	if (print == 1)
		ft_putendl("");
	ft_putendl("");
}
