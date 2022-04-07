/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:52 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/07 08:49:56 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	arg_errors(int n, char *str)
{
	if (n == 1)
		ft_putendl("usage: ./ft_ls <ls> <flags> <filename>");
	else if (n == 2)
	{
		ft_putstr("command not found: ");
		ft_putendl(str);
	}
	else if (n == 3)
		ft_putendl("wrong flag or no flags");
	exit(1);
}
