/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utility_functions_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:45:29 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/16 15:23:46 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function only serves to find out the number of files/directories/links
** etc in the current directory. It returns an integer.
*/
int	file_and_directory_count(const char *dirname, int count)
{
	DIR				*d;
	struct dirent	*entity;

	d = opendir(dirname);
	if (d == NULL)
		return (0);
	entity = readdir(d);
	while (entity != NULL)
	{
		entity = readdir(d);
		count++;
	}
	closedir(d);
	return (count);
}

t_data	*store_flags(t_data *to_save, char **str, int i)
{
	while (str[i] != NULL)
	{
		if (str[i][0] == '-')
		{
			to_save = flag_check(to_save, str[i]);
			to_save->flag_args++;
			i++;
		}
		else
			return (to_save);
	}
	return (to_save);
}

t_data	*store_rest(t_data *to_save, char **str, int i)
{
	int		index;
	int		nb;

	if (str[i - 1] == NULL)
		return (to_save);
	nb = to_save->arg_count;
	index = 0;
	to_save->list = (char **)malloc(sizeof(char *) * nb + 1);
	while (str[i] != NULL)
	{
		to_save->list[index] = ft_strdup(str[i]);
		index++;
		i++;
	}
	to_save->list[index] = NULL;
	return (to_save);
}

void	handle_files(t_data *to_print, int i, int index)
{
	check_access(to_print, 0);
	while (to_print->list[i] != NULL)
	{
		while (index < to_print[0].count)
		{
			if (ft_strcmp(to_print[index].f_name, to_print->list[i]) == 0 && \
				to_print[index].access != -1)
			{
				ft_putstr(to_print[index].f_name);
				ft_putstr("  ");
				index = 0;
				i++;
				if (to_print->list[i] == NULL)
					return ;
			}
			index++;
			/*ft_putnbr_endl(i);
			ft_putnbr_endl(index);
			ft_putendl(to_print[index].f_name);*/
		}
		i++;
	}
}
