/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:54 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/20 19:24:59 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This print_ls_a function prints all the files/directories/links etc in the
** current directory. TO-DO: ADD FLAG DETECTION AND CALLS ACCORDINGLY.
**
*/
void	print_ls_a(t_data *to_print, int i)
{
	while (i < to_print[0].count)
	{
		ft_putstr(to_print[i].f_name);
		ft_putstr("  ");
		i++;
	}
	ft_putendl("");
}

/*
** Function which opens a directory stream and reads each entry in
** the current directory to a an array of structs *f. No NULL check
** needed for ft_memalloc as it has inbuild exit in case malloc fails.
*/
t_data	*ls_extra(const char *dirname, t_data *f, int i)
{
	DIR				*dir;
	struct dirent	*entity;
	int				count;

	count = file_and_directory_count(dirname, 0);
	f = ft_memalloc(count * sizeof(t_data));
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

t_data	*store_arguments(t_data *to_save, char **str, int i)
{
	t_data	*tmp;

	tmp = to_save;
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
			to_save = flag_check(tmp, str[i]);
		/*else
		{
			to_save->list = (char**)malloc(sizeof(char*);
		}*/
		i++;

	}
	to_save->flag_args = i;
	ft_putnbr_endl(to_save->flag_args);
	return (to_save);
}


void	ls_with_extra(t_data *arr_of_s, char **str)
{
	arr_of_s = store_arguments(arr_of_s, str, 2);
	arr_of_s = ls_extra(".", arr_of_s, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);
	ft_putnbr_endl(arr_of_s->flag_args);
	print_ls_a(arr_of_s, 0);
}
