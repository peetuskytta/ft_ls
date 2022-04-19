/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_with_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:29:54 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/19 18:32:18 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This print_ls_a function prints all the files/directories/links etc in the
** current directory. TO-DO: ADD FLAG DETECTION AND CALLS ACCORDINGLY.
**
*/
static void	print_ls_a(t_data *to_print, int i)
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

t_args	*store_arguments(t_args *to_save, char **str, int i, int nb)
{
	int		index;
	t_args	*tmp;

	tmp = to_save;
	index = 0;
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			to_save = flag_check(tmp, str[i]);
		}
		else
		{
			to_save->list = (char **)malloc(sizeof(char*) * nb - 2);
			to_save->list[index] = ft_strdup(str[i]);
			index++;
		}
		i++;
	}
	//to_save->list[nb + 1] = NULL;
	//to_save->count = index;
	//print_double(to_save->list);
	return (to_save);
}

void	ls_with_extra(t_data *arr_of_s, t_args *args, char **str, int nb)
{
	t_args	*tmp;

	tmp = store_arguments(args, str, 2, nb);
	ft_putendl("here 2.1");
	print_double(tmp->list);
	arr_of_s = ls_extra(".", arr_of_s, 0);
	arr_of_s = a_to_z_sort(arr_of_s, arr_of_s->count);

	print_ls_a(arr_of_s, 0);
	//ft_putendl("");
}