/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/17 15:52:35 by pskytta          ###   ########.fr       */
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

void	print_ls_err(char *name)
{
	print_filename(name);
	ft_putstr("ls: ");
	ft_putstr(name);
	error_prints(1, ": Permissions denied");
}

void	print_filename(char *name)
{
	ft_putendl("");
	ft_putstr(name);
	ft_putendl(":");
}
