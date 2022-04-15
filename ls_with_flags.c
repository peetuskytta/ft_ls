/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:54 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/15 17:42:53 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This print_ls_a function prints all the files/directories/links etc in the
** current directory. TO-DO: ADD FLAG DETECTION AND CALLS ACCORDINGLY.
**
*/
static void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putstr(to_print[i].f_name);
		ft_putstr("  ");
		i++;
	}
	ft_putendl("");
}

/*
** Function which opens a directory stream and reads each entry in
** the current directory to a an array of structs *f. No NULL check
** needed for ft_memalloc as it has inbuild exit in case malloc fails.
*/
static t_data	*ls_extra(const char *dirname, t_data *f, int i, int count)
{
	DIR				*dir;
	struct dirent	*entity;

	count = file_and_directory_count(dirname, count);
	f = ft_memalloc(count * sizeof(t_data));
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		f[i].f_name = ft_strdup(entity->d_name);
		f[i].type = entity->d_type;
		f[i].name_len = ft_strlen(entity->d_name);
		f[i].count = count;
		entity = readdir(dir);
		i++;
	}
	closedir(dir);
	return (f);
}

t_data	*store_arguments(t_data *to_store, char **str, int i)
{
	int	index;

	index = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
			to_store = flag_check(to_store, str[i]);
		else
		{
			to_store->list[index] = ft_strdup(str[i]);
			index++;
		}
		i++;
	}
	return (to_store);
}

void	ls_with_extra(t_data *arr_of_s, char **string)
{
	int	i = 0;

	arr_of_s = store_arguments(arr_of_s, string, 2);
	arr_of_s = ls_extra(".", arr_of_s, 0, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);
	while (i < 5)
	{
		ft_putnbr(arr_of_s->flags[i]);
		ft_putendl("");
		i++;
	}
	print_ls_a(arr_of_s, 0);
	//ft_putendl("");
}