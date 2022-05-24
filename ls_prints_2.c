/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:56:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/24 08:50:14 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_data *arr, int i)
{
	if (arr->flags[1] == 0)
		i = arr->start;
	while (arr->count > i)
	{
		print_rights(&arr[i].info);
		ft_putnbr(arr[i].info.st_nlink);
		ft_putstr("	");
		ft_putstr(arr[i].f_name);
		ft_putendl("");
		i++;
	}
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
	ft_putstr("	");
}
