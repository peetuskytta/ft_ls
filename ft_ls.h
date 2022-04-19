/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/19 18:21:28 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_data
{
	char	*f_name;
	int		type;
	int		name_len;
	int		count;
}	t_data;

typedef struct s_args
{
	char	**list;
	int		flags[5];
	int		count;
}	t_args;


int		argument_check(int count, char **str);
int		file_and_directory_count(const char *dirname, int count);
t_args	*flag_check(t_args *args, char *str);
t_args	*store_arguments(t_args *to_save, char **str, int i, int nb);
t_data	*a_to_z_sort(t_data *to_sort, int n);
t_data	*ls_extra(const char *dirname, t_data *f, int i);
t_data	*simple_ls(const char *dirname, t_data *f, int i, int count);
t_data	*sort_driver(t_data *to_sort, t_args *args);
void	ch_error(char c);
void	error_prints(int n, char *str);
void	flag_save(char c, t_args *arguments);
void	ls_with_extra(t_data *arr_of_s, t_args *args, char **str, int nb);
void	only_ls(t_data *arr_of_s);
void	print_double(char **str);

#endif
