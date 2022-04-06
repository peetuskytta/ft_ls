/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/06 14:56:24 by pskytta          ###   ########.fr       */
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
