/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:16:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/05 16:01:31 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	action_check(int n)
{
	if (n == 2)
		return (1);
	if (n == 3)
		return (2);
	if (n > 3)
		return (3);
	else
		return (0);
}

char	**save_argv(char **av, int count, char **command)
{
	int	i;

	i = 1;
	command = (char **)malloc(sizeof(char) * count + 1);	
	command[count - 1] = NULL;
	while (i < count)
	{
		command[i - 1] = ft_strdup(av[i]);
		i++;
	}
	return (command);
}

int	main(int argc, char **argv)
{
	int		action;
	char	**command;

	command = NULL;
	if (argc < 2)
		print_error(1);
	command = save_argv(argv++, argc, command);
	action = action_check(argc);
//	ft_putnbr(action);
//	ft_putendl("");
//	ft_putnbr(argc);
//	ft_putendl("");
	print_double(command);

// FREE THE MEMORY ALLOCATED FOR THE COMMAND LINE	
	return (0);
}
