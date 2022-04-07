/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/07 19:59:35 by pskytta          ###   ########.fr       */
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
	int		*flags[5];
	t_data	*ptr;
	int		i;

	i = 0;
	ft_bzero(flags, 5);
	if (argument_check(argc, argv) == 1)
	{
		ptr = list_files(".", 0, 0);

		while (i < ptr[0].count)
		{
			ft_putendl(ptr[i].f_name);
			i++;
		}
	}
	else
		arg_errors(1, "");
	return (0);
}
