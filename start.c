/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:16:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/04 16:32:36 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	*data;
	int		action;

	action = action_check(argc);
	data = allocate(argv, 1);

//	ft_putnbr(action);
//	ft_putendl("");
	ft_putendl(data->command);
	ft_putendl(data->flags);
	
	return (0);
}
