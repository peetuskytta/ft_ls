/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/16 15:17:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>

typedef struct s_data
{
	char	f_name[256];
	int		type;
	int		name_len;
	int		count;
	int		flags[5];
	int		flag_args;
	int		arg_count;
	char	**list;
	int		access;
	struct	stat info;
}	t_data;

int		argument_check(int count, char **str);
int		check_list(char *name, char **list);
int		file_and_directory_count(const char *dirname, int count);
t_data	*a_to_z_sort(t_data *to_sort, int n);
t_data	*flag_check(t_data *arguments, char *str);
t_data	*ls_extra(const char *dirname, t_data *arr, int i, int count);
t_data	*only_ls(t_data *arr_of_s);
t_data	*simple_ls(const char *dirname, t_data *arr, int i);
t_data	*store_arguments(t_data *to_save, char **str);
t_data	*store_flags(t_data *to_save, char **str, int i);
t_data	*store_rest(t_data *to_save, char **str, int i);
void	access_right(const char *name, t_data *rights);
void	ch_error(char c);
void	check_access(t_data *to_check, int i);
void	error_prints(int n, char *str);
void	handle_files(t_data *to_print, int i, int index);
void	ls_with_extra(t_data *arr_of_s, char **str);
void	non_exist(char c);
void	print_double(char **str);
void	print_ls(t_data *to_print, int i);
void	print_ls_a(t_data *to_print, int i);

#endif
