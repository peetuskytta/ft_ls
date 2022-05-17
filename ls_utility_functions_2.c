/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utility_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:02:55 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/17 15:53:38 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_access(t_data *to_check, int i, char *path)
{
	t_data	*temp;

	temp = ft_memalloc(sizeof(t_data));
	while (i < to_check->count)
	{
		if (check_list(to_check[i].f_name, to_check->list) == 1 && \
			to_check[i].type == DT_DIR)
		{
			path_maker(path, to_check[i].f_name);
			if ((to_check[i].access) == -1)
				print_ls_err(to_check[i].f_name);
			else
			{
				print_filename(to_check[i].f_name);
				only_ls(temp, path);
				i++;
			}
		}
		i++;
	}
	free(temp);
}

void	path_maker(char *start, char *name)
{
	ft_strclr(start);
	ft_strcat(start, ".");
	ft_strcat(start, "/");
	ft_strcat(start, name);
}

int	check_list(char *name, char **list)
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
}

void	access_right(const char *name, t_data *rights)
{
	if (stat(name, &rights->info) != 0)
		error_prints(3, "syscall stat failed");
	if (rights->type == DT_DIR)
	{
		if (rights->info.st_mode & R_OK)
			rights->access = 0;
		else
			rights->access = -1;
	}
}
