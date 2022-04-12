/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 21:51:15 by pskytta          ###   ########.fr       */
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

/*
** Function which opens a directory stream and reads each entry in
** the current directory to a an array of structs *f. No NULL check
** needed for ft_memalloc as it has inbuild exit in case malloc fails.
*/
t_data	*list_files_and_directories(const char *dirname, int i, int count)
{
	DIR				*dir;
	struct dirent	*entity;

	count = file_and_directory_count(dirname, count);
	t_data	*f = ft_memalloc(count * sizeof(t_data));
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

	arr_of_s = ft_memalloc(sizeof(t_data));
	if (argument_check(argc, argv) == 1)
		only_ls(arr_of_s);
	else if (argument_check(argc, argv) == 2)
		ls_with_flags(arr_of_s, argv);
	else
		error_prints(1, "usage: ./ft_ls <ls> <flags> <filename>");
	return (0);
}
