/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/05 15:51:16 by pskytta          ###   ########.fr       */
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

void	print_error(int n)
{
	if (n == 1)
	{
		ft_putendl("usage: ./ft_ls <ls> <flags> <filename>");
		exit(1);
	}
	if (n == 2)
		ft_putendl("other mistake?");
	else
		ft_putendl("error");
}
