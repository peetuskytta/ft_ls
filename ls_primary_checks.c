/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_primary_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:51:47 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/21 15:55:57 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Based on the amount of arguments it is possible to define some actions.
** Argument 1 is always the executable <./ft_ls>. If argument count n equals
** to 2 we know that there's only one command. If it is "ls" we continue.
** If n is 3 there are additional flags to the "ls" command. If n is larger
** than 3 there are additional file/dirextory-names to be considered
*/
static int	action_check(int n)
{
	if (n == 2)
		return (1);
	if (n > 2)
		return (2);
	else
		return (0);
}

/*
** flags[5] = flags[l][a][r][R][t] and are initialized all to zero.
** if a flag is found the corresponding position is changed to 1.
*/
static void	flag_save(char c, t_data *arguments)
{
	if (c == 'l')
		arguments->flags[0] = 1;
	else if (c == 'a')
		arguments->flags[1] = 1;
	else if (c == 'r')
		arguments->flags[2] = 1;
	else if (c == 'R')
		arguments->flags[3] = 1;
	else if (c == 't')
		arguments->flags[4] = 1;
	else
		error_prints(5, &c);
}

t_data	*flag_check(t_data *arguments, char *str)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(str);
	if (len == 2)
		flag_save(str[1], arguments);
	if (len > 2)
	{
		while (str[i] != '\0')
		{
			flag_save(str[i], arguments);
			i++;
		}
	}
	if (len == 1)
		error_prints(6, &str[0]);
	return (arguments);
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
