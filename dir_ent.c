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

int	main(int argc, char *argv[])
{
	DIR				*dir;
	struct dirent	*entity;

	dir = opendir(".");
	if (dir == NULL)
		return (1);
	entity = readdir(dir);
	while (entity != NULL)
	{
		ft_putnbr(entity->d_type);
		ft_putchar(' ');
		ft_putnbr(entity->d_ino);
		ft_putchar(' ');
		ft_putnbr(entity->d_off);
		ft_putchar(' ');
		ft_putnbr(entity->d_reclen);
		ft_putchar(' ');
		ft_putendl(entity->d_name);
		entity = readdir(dir);
	}

	closedir(dir);
	return (0);
}