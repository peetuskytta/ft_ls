/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_ent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/15 11:26:31 by pskytta          ###   ########.fr       */
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

/*void	free_struct(t_data *to_free, int n, int i)
{
	while (i < n)
	{
		free(to_free[i].f_name);
		to_free[i].f_name = NULL;
		i++;
	}
}*/

int	main(int argc, char *argv[])
{
	t_data	*arr_of_s;

	arr_of_s = ft_memalloc(sizeof(t_data));
	if (argument_check(argc, argv) == 1)
		only_ls(arr_of_s);
	else if (argument_check(argc, argv) > 1)
		ls_with_extra(arr_of_s, argv);
	else
		error_prints(1, "usage: ./ft_ls <ls> <flags> <filename>");
	return (0);
}