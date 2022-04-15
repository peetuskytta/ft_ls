/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_no_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:03:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/15 11:30:04 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_ls(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		if (to_print[i].f_name[0] != '.')
		{
			ft_putstr(to_print[i].f_name);
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
static t_data	*simple_ls(const char *dirname, t_data *f, int i, int count)
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

void	only_ls(t_data *arr_of_s)
{
	arr_of_s = simple_ls(".", arr_of_s, 0, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);
	print_ls(arr_of_s, 0);
}