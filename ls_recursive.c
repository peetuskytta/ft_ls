/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:07:22 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/14 08:07:22 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
t_data	*save_data(t_data *f, int i)
{
	f[i].f_name = ft_strdup(entity->d_name);
	f[i].type = entity->d_type;
	f[i].name_len = ft_strlen(entity->d_name);
	f[i].count = count;
}

t_data	*list_files_and_directories(const char *dirname, t_data *f, int i, int count)
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
		f[i] = save_data(f, i);
		entity = readdir(dir);
		i++;
	}
	closedir(dir);
	return (f);
}

*/