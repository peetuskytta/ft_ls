/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:52 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 14:59:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error_prints(int n, char *str)
{
	if (n == 1)
		ft_putendl(str);
	else if (n == 2)
	{
		ft_putstr("command not found: ");
		ft_putendl(str);
	}
	else if (n == 3)
		ft_putendl("wrong flag or no flags");
	else if (n == 4)
		ft_putendl(str);
	exit(1);
}
