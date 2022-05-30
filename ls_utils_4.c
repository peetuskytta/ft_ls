/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:26:02 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/30 10:26:02 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	long_with_hidden(t_data *arr, int i)
{
	while (i < arr->count)
	{
		print_rights(&arr[i].info);
		print_nb_links(arr[i].info.st_nlink, arr->padding[0]);
		print_users(&arr[i].info);
		print_size(arr[i].info.st_size, arr->padding[1]);
		print_t_mod(&arr[i].info);
		ft_putstr(arr[i].f_name);
		ft_putendl("");
		i++;
	}
}

void	long_without_hidden(t_data *arr, int i)
{
	while (i < arr->count)
	{
		if (arr[i].f_name[0] != '.')
		{
			print_rights(&arr[i].info);
			print_nb_links(arr[i].info.st_nlink, arr->padding[0]);
			print_users(&arr[i].info);
			print_size(arr[i].info.st_size, arr->padding[1]);
			print_t_mod(&arr[i].info);
			ft_putstr(arr[i].f_name);
			ft_putendl("");
		}
		i++;
	}
}

void	long_args(t_data *arr, int i)
{
	while (i < arr->count)
	{
		if (!(arr[i].info.st_mode & S_IFDIR))
		{
			print_rights(&arr[i].info);
			print_nb_links(arr[i].info.st_nlink, arr->padding[0]);
			print_users(&arr[i].info);
			print_size(arr[i].info.st_size, arr->padding[1]);
			print_t_mod(&arr[i].info);
			ft_putstr(arr[i].f_name);
			ft_putendl("");
		}
		i++;
	}
	args_dirs(arr, 0, arr->path);
}

void	args_dirs(t_data *arr, int i, char *path)
{
	t_data	*temp;

	temp = ft_memalloc(sizeof(t_data));
	copy_info(temp, arr);
	while (i < arr->count)
	{
		if (arr[i].info.st_mode & S_IFDIR && arr[i].info.st_mode & R_OK)
		{
			path_maker(path, arr[i].f_name);
			if (arr->arg_count > 1)
				print_filename(arr[i].f_name, 1);
			if (arr->count < i + 1)
			ft_putendl(path);
			ls_l_flags(temp, path);
		}
		if (!(arr[i].info.st_mode & R_OK))
		{
			print_dir_access_err(arr[i].f_name, arr->arg_count);
		}
		i++;
	}
	free(temp);
}

void	copy_info(t_data *temp, t_data *arr)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		temp->flags[i] = arr->flags[i];
		i++;
	}
	temp->off = 1;
}