/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/08 01:10:50 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	file_count(const char *dirname, int count)
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

t_data	*list_files(const char *dirname, int i, int count)
{
	DIR				*dir;
	struct dirent	*entity;
	t_data			*file;

	count = file_count(dirname, count);
	file = malloc(count * sizeof(t_data));
	dir = opendir(dirname);
	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
			file[i].f_name = ft_strdup(entity->d_name);
			file[i].type = entity->d_type;
			file[i].name_len = ft_strlen(entity->d_name);
			file[i].count = count;
			entity = readdir(dir);
			i++;
	}
	closedir(dir);
	return (file);
}
int	main(int argc, char *argv[])
{
	int		flags[5];
	t_data	*ptr;

	ft_bzero(flags, 5);
	ptr = argument_check(argc, argv, flags);
	ft_putendl(ptr[0].f_name);

	return (0);
}
