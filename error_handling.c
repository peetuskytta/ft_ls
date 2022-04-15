/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:52 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/15 09:39:47 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_prints(int n, char *str)
{
	if (n == 1)
	{
		ft_putendl(str);
		return ;
	}
	if (n == 2)
	{
		ft_putstr("command not found: ");
		ft_putendl(str);
	}
	if (n == 3)
	{
		ft_putstr("error: ");
		ft_putendl(str);
	}
	if (n == 4)
		ft_putendl(str);
	if (n == 5)
		ch_error(*str);
	exit(1);
}

void	ch_error(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("");
}
