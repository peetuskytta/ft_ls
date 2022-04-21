/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:45:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/21 15:48:41 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function only serves to find out the number of files/directories/links
** etc in the current directory. It returns an integer.
*/
int	file_and_directory_count(const char *dirname, int count)
{
	DIR				*d;
	struct dirent	*entity;

	d = opendir(dirname);
	if (d == NULL)
		return (0);
	entity = readdir(d);
	while (entity != NULL)
	{
		entity = readdir(d);
		count++;
	}
	closedir(d);
	return (count);
}

t_data	*store_arguments(t_data *to_save, char **str)
{
	to_save = store_flags(to_save, str, 2);
	to_save = store_rest(to_save, str, to_save->flag_args + 2);
	return (to_save);
}

t_data	*store_flags(t_data *to_save, char **str, int i)
{
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			to_save = flag_check(to_save, str[i]);
			to_save->flag_args++;
			i++;
		}
		else
			return (to_save);
	}
	return (to_save);
}

t_data	*store_rest(t_data *to_save, char **str, int i)
{
	int		index;
	int		nb;

	if (str[i - 1] == NULL)
		return (to_save);
	nb = to_save->arg_count;
	index = 0;
	to_save->list = (char **)malloc(sizeof(char *) * nb);
	while (str[i] != NULL)
	{
		to_save->list[index] = ft_strdup(str[i]);
		index++;
		i++;
	}
	to_save->list[index] = NULL;
	return (to_save);
}
