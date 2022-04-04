/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:52:31 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/04 13:00:04 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_double(char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		ft_putendl(str[i]);
		i++;
	}
}

void	print_error(void)
{
	ft_putendl("error");
}
