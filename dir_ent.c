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

int	file_count(const char *dirname, int count)
{
	DIR				*d;
	struct dirent	*ent;

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

void	list_files(const char *dirname, int i, int count)
{
	DIR				*dir;
	struct dirent	*entity;
	char			**files;

	count = file_count(dirname, count);
	files = (char **)malloc(sizeof(char) * count + 1);
//	ft_putnbr(count);
	dir = opendir(dirname);
	if (dir == NULL)
		return ;
	entity = readdir(dir);
	while (entity != NULL)
	{
		if (entity->d_name[0] != '.')
		{
			files[i] = ft_strdup(entity->d_name);
			print_2ws(entity->d_name);
			i++;
		}
		entity = readdir(dir);
	}
	//print_double(files);
	closedir(dir);
}
int	main(int argc, char *argv[])
{
	if (argument_check(argc, argv) == 1)
		list_files(".", 0, 0);
	else
		arg_errors(1, "");
//	ft_putstr("\033[30G");
//	ft_putendl("hello");
	return (0);
}