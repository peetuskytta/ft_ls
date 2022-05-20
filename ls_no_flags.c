/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:03:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/20 16:33:06 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_ls(t_data *to_print, int i)
{
	while (i < to_print->count)
	{
		if (to_print[i].f_name[0] != '.')
		{
			ft_putstr(to_print[i].f_name);
			if (to_print->count >= i + 1)
				ft_putstr("  ");
		}
		i++;
	}
	ft_putendl("");
}

/*
** Function which opens a directory stream and reads each entry in
** the current directory to a an array of structs *f. No NULL check
** needed for ft_memalloc as it has inbuild exit in case malloc fails.
*/
t_data	*simple_ls(const char *dirname, t_data *arr, int i)
{
	int				count;
	DIR				*dir;
	t_data			*f;
	struct dirent	*entity;

	count = file_and_directory_count(dirname, 0);
	f = ft_memalloc(count * sizeof(t_data));
	f = arr;
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		ft_strcpy(f[i].f_name, entity->d_name);
		f[i].count = count;
		entity = readdir(dir);
		i++;
	}
	closedir(dir);
	dot_file_count(arr, 0);
	return (f);
}

void	only_ls(t_data *arr_of_s, char *name)
{
	arr_of_s = simple_ls(name, arr_of_s, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);
	print_ls(arr_of_s, 0);
}
