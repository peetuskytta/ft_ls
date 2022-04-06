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

void	list_files(const char *dirname)
{
	DIR				*dir;
	struct dirent	*entity;

	dir = opendir(dirname);
	if (dir == NULL)
		return;
	
	ft_putstr("Reading files in: ");
	ft_putendl(dirname);

	entity = readdir(dir);
	while (entity != NULL)
	{
		ft_putnbr(entity->d_type);
		ft_putchar(' ');
		//ft_putnbr(entity->d_ino);
		//ft_putchar(' ');
		//ft_putnbr(entity->d_off);
		//ft_putchar(' ');
		//ft_putnbr(entity->d_reclen);
		//ft_putchar(' ');
		ft_putstr(dirname);
		ft_putendl(entity->d_name);
		if (entity->d_type == DT_DIR && ft_strcmp(entity->d_name, ".") != 0 && ft_strcmp(entity->d_name, "..") != 0)
		{
			char	path[100] = {0};
			ft_strcat(path, dirname);
			ft_strcat(path, "/");
			ft_strcat(path, entity->d_name);
			list_files(path);
		}
		entity = readdir(dir);
	}
	closedir(dir);
}
int	main(int argc, char *argv[])
{
	list_files(".");
	return (0);
}