/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utility_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:55 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/22 19:27:04 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_dir_access(t_data *arr, int i, char *path)
{
	t_data	*temp;

	temp = ft_memalloc(sizeof(t_data));
	while (arr->list[i] != NULL)
	{
		if (stat(arr->list[i], &arr->info) == 0 && \
			arr->info.st_mode & S_IFDIR && \
			arr->info.st_mode & R_OK)
		{
			path_maker(path, arr->list[i]);
			if (arr->arg_count > 1)
				print_filename(arr->list[i]);
			only_ls(temp, path);
			if (arr->list[i + 1] != NULL)
				ft_putendl("");
		}
		if (!(arr->info.st_mode & R_OK) && arr->info.st_mode & S_IFDIR)
			print_dir_access_err(arr->list[i], arr->arg_count);
		i++;
	}
	free(temp);
}

/*
** Function that makes creates a path for the name given.
** TODO -> add reverse path with int 1 or 0 indicator.
*/
void	path_maker(char *start, char *name)
{
	ft_strclr(start);
	ft_strcat(start, ".");
	ft_strcat(start, "/");
	ft_strcat(start, name);
}

/*int	check_dirname(char *name, char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		if (ft_strcmp(list[i], name) == 0)
			return (1);
		else
			i++;
	}
	return (0);
}*/
