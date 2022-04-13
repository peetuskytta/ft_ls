/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:51:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/13 08:26:55 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Based on the amount of arguments it is possible to define some actions.
** Argument 1 is always the executable <./ft_ls>. If argument count n equals to
** 2 we know that there's only one command. If it is "ls" we continue.
** If n is 3 there are additional flags to the "ls" command. If n is larger than
** 3 there are additional file/directory-names to be considered
*/
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

/*
** flags[5] = flags[l][a][r][R][t] and are initialized all to zero.
** if a flag is found the corresponding position is changed to 1.
*/
/*void	flag_check(char **str, int *flags, int i)
{
	if (str[i][0] == '-' && ft_strlen(str[i]) == 2)
	{
		if (str[i][1] == 'l')
			flags[0] = 1;
		if (str[i][1] == 'a')
			flags[1] = 1;
		if (str[i][1] == 'r')
			flags[2] = 1;
		if (str[i][1] == 'R')
			flags[3] = 1;
		if (str[i][1] == 't')
			flags[4] = 1;
		else
			return ;
	}
	error_prints(3, "");
}*/

/*
** Funtion checks if the second argument (argv[1]) is 'ls'. In case it is
** not ls the function exits through arg_error() function. If no string it
** returns and main outputs usage error message.
*/
static void	ls_check(char *str)
{
	if (str[1])
	{
		if (ft_strcmp(str, "ls") != 0)
			error_prints(2, str);
	}
	else
	{
		ft_putendl("wrong");
		arg_errors(1, "");
	}
}

int	argument_check(int count, char **str)
{
	ls_check(str[1]);
	return (action_check(count));
}
