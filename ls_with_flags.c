/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:54 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/24 08:58:06 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This print_ls_a function prints all the files/directories/links etc in the
** current directory. TO-DO: ADD FLAG DETECTION AND CALLS ACCORDINGLY.
**
*/
void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putstr(to_print[i].f_name);
		if (to_print[0].count != i + 1)
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
t_data	*dir_stream(const char *dirname, t_data *arr, int i, int count)
{
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
		f[i].len = ft_strlen(f[i].f_name);
		stat(f[i].f_name, &f[i].info);
		entity = readdir(dir);
		i++;
	}
	closedir(dir);
	sort_by_flag(arr);
	return (f);
}

/*
** Driver function when there are more than 2 arguments (argc).
*/
void	ls_with_extra(t_data *arr, char **str, const char *name)
{
	arr = store_arguments(arr, str);
	if (arr->list[0] != NULL)
	{
		exist_check(arr, 0);
		check_dir_access(arr, 0, arr->path);
	}
	else
	{
		arr = dir_stream(name, arr, 0, 0);
		if (arr->flags[0] == 1)
			print_long(arr, 0);
		else
			print_ls_a(arr, 0);
	}
}

void	exist_check(t_data *to_check, int i)
{
	print_nonexist(to_check, i);
	print_exists(to_check, i);
}
