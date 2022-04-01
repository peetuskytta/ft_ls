/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:16:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/01 16:24:33 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	primary_checks(int n, char *line)
{
	if (n == 2 && ft_strequ(&line, "ls") == 0) //we have on ly ls
		ft_putendl("Do only ls");
	if (n == 3) // indicates we have flags
		ft_putendl("Do ls and consider flags");
	if (n > 3)
		ft_putendl("Do ls, consider flags, to 'n' file(s)");
}

void	print_double(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_putendl(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		ft_putendl("Not enough arguments.");
	primary_checks(argc, argv);
}
