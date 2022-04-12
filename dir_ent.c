/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 15:50:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_data	*list_files_and_directories(const char *dirname, int i, int count)
{
	DIR				*dir;
	struct dirent	*entity;

	count = file_and_directory_count(dirname, count);
	t_data	*f = malloc(count * sizeof(t_data));
	if (f == NULL)
		error_prints(4, "malloc failed in 'list_files_and_directories()'");
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

int	main(int argc, char *argv[])
{
	t_data	*arr_of_s;

	arr_of_s = NULL;
	if (argument_check(argc, argv) == 1)
		only_ls(arr_of_s);
	else if (argument_check(argc, argv) == 2)
		ls_with_flags(arr_of_s, argv);
	else
		error_prints(1, "usage: ./ft_ls <ls> <flags> <filename>");
	return (0);
}
