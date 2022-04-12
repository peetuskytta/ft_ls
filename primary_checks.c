/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:51:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 15:50:24 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Based on the amount of arguments it is possible to define some actions.
** Argument 1 is always the executable <./ft_ls>. If argument count n equals to
** 2 we know that there's only one command. If it is "ls" we continue.
** If n is 3 there are additional flags to the "ls" command. If n is larger than
** 3 there are additional file/dirextory-names to be considered
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
** Funtion checks if the second argument (argv[1]) is 'ls'. In case it is
** not ls the function exits through arg_error() function. If no string it
** returns and main outputs usage error message.
*/
static void	ls_check(char *str)
{
	if (str)
	{
		if (ft_strcmp(str, "ls") != 0)
			error_prints(2, str);
	}
}


int	argument_check(int count, char **str)
{
	ls_check(str[1]);
	return (action_check(count));
}
