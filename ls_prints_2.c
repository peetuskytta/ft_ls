/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:56:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/23 15:01:30 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_data *arr, int i)
{
	if (arr->flags[1] == 1)
		i = arr->start;
	while (arr->count > i)
	{
		//print_filename(arr[i].f_name, 0);
		check_rights(&arr[i].info);
		ft_putendl("");
		i++;
	}
}

void	check_rights(struct stat *stats)
{
	char	str[11];

	ft_strncpy(str, "----------", 10);
	check_usr(stats->st_mode, str);
	check_grp(stats->st_mode, str);
	check_oth(stats->st_mode, str);
	ft_putstr(str);
	ft_putstr(" ");
}

void	check_usr(int mode, char *str)
{
	if (mode & S_IRUSR)
		str[1] = 'r';
	if (mode & S_IWUSR)
		str[2] = 'w';
	if (mode & S_IXUSR)
		str[3] = 'x';
}

void	check_grp(int mode, char *str)
{
	if (mode & S_IRGRP)
		str[4] = 'r';
	if (mode & S_IWGRP)
		str[5] = 'w';
	if (mode & S_IXGRP)
		str[6] = 'x';
}

void	check_oth(int mode, char *str)
{
	if (mode & S_IROTH)
		str[7] = 'r';
	if (mode & S_IWOTH)
		str[8] = 'w';
	if (mode & S_IXOTH)
		str[9] = 'x';
}
