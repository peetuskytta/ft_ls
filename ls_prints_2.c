/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_prints_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:56:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/30 08:54:44 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_data *arr, int i)
{
	if (arr->list[0] == NULL || arr->off == 1)
	{
		if (arr->flags[1] == 1)
			long_with_hidden(arr, i);
		else
			long_without_hidden(arr, i);
	}
	else
		long_args(arr, i);
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

void	print_l_list(t_data *arr, int i)
{
	t_data	*f;
	int		nb;

	nb = arr->arg_count - arr->flag_args;
	f = ft_memalloc((nb) * sizeof(t_data));
	f = arr;
	while (arr->list[i] != NULL)
	{
		ft_strcpy(f[i].f_name, arr->list[i]);
		f[i].count = nb;
		stat(f[i].f_name, &f[i].info);
		i++;
	}
	save_padding(arr, 0);
	print_long(arr, 0);
}
