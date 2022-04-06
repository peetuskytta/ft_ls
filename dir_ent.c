/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:45:40 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/06 07:45:40 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t	file_count(const char *dirname)
{
	DIR				*d;
	size_t			count;
	struct dirent	*ent;

	count = 1;
	d = opendir(dirname);
	if (d == NULL)
		return (0);
	ent = readdir(d);
	while (ent != NULL)
	{
		ent = readdir(d);
		count++;
	}
	closedir(d);
	return (count);
}

void	list_files(const char *dirname)
{
	DIR				*dir;
	struct dirent	*entity;

	dir = opendir(dirname);
	if (dir == NULL)
		return ;
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (entity->d_name[0] != '.')
			print_2ws(entity->d_name);
		entity = readdir(dir);
	}
	ft_putendl("");
	closedir(dir);
}
int	main(int argc, char *argv[])
{
	if (argument_check(argc, argv) == 1)
		list_files(".");
	else
		arg_errors(1, "");
	return (0);
}