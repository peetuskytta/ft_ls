/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:45:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/30 11:56:25 by pskytta          ###   ########.fr       */
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

t_data	*store_flags(t_data *save, char **str, int i)
{
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			save = flag_check(save, str[i]);
			save->flag_args++;
			i++;
		}
		else
			return (save);
	}
	return (save);
}

t_data	*store_rest(t_data *save, char **str, int i)
{
	int		index;
	int		nb;

	if (str[i - 1] == NULL)
		return (save);
	nb = save->arg_count;
	index = 0;
	save->list = (char **)malloc(sizeof(char *) * nb + 1);
	while (str[i] != NULL)
	{
		save->list[index] = ft_strdup(str[i]);
		index++;
		i++;
	}
	save->list[index] = NULL;
	if (save->arg_count > 2)
		argument_sort(save->list, nb - save->flag_args);
	return (save);
}

void	dot_file_count(t_data *arr, int i)
{
	arr->start = 0;
	while (i < arr->count)
	{
		if (arr[i].f_name[0] == '.')
			arr->start++;
		i++;
	}
}
