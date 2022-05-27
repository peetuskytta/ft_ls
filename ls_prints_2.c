/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:56:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/27 09:46:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_data *arr, int i)
{
	if (arr->flags[1] == 0)
		i = arr->start;
	//ft_putnbr_endl(arr[0].info.st_blksize);
	//ft_putnbr_endl(arr[0].info.st_blocks);
	while (arr->count > i)
	{
		print_rights(&arr[i].info);
		space_after_nbr(arr[i].info.st_nlink);
		print_users(&arr[i].info);
		print_size(arr[i].info.st_size, arr->padding[1]);
		//print_t_mod(arr[i].info->st_mtim);
		ft_putstr(arr[i].f_name);
		ft_putendl("");
		i++;
	}
}

void	print_users(struct stat *stats)
{
	struct passwd *pw;
	struct group *gr;

	pw = NULL;
	gr = NULL;
	pw = getpwuid(stats->st_uid);
	space_after_str(pw->pw_name);
	gr = getgrgid(stats->st_gid);
	space_after_str(gr->gr_name);
}

void	print_rights(struct stat *stats)
{
	char	str[11];

	ft_strncpy(str, "----------", 10);
	check_file_type(stats->st_mode, str);
	check_usr(stats->st_mode, str);
	check_grp(stats->st_mode, str);
	check_oth(stats->st_mode, str);
	ft_putstr(str);
	ft_putstr(" ");
}
