/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/11 15:50:36 by pskytta          ###   ########.fr       */
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

	count = file_count(dirname, count);
	t_data	*f = malloc(count * sizeof(t_data));
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
	int		i;

	i = 0;
	if (argument_check(argc, argv) == 1)
	{
		arr_of_s = list_files(".", 0, 0);
		print_ls(arr_of_s, 0);
	}
	else
		arg_errors(1, "");
	return (0);
}
