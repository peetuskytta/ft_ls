/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:18:55 by pskytta           #+#    #+#             */
/*   Updated: 2022/06/20 18:01:19 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>

# define MAX_PATH 4096
# define TRUE 1
# define FALSE 0
# define NO_ACCESS 0

typedef struct s_data
{
	int				f_all;
	int				f_long;
	int				f_reve;
	int				f_recu;
	int				f_time;
	int				nb_of_args;
	int				file_count;
	int				flag_count;
	int				link_count;
	int				arg_count;
	int				arguments_on;
	int				f_d_count[2];
	DIR				*dir;
	struct dirent	*ent;
}	t_data;

typedef struct s_file
{
	char			name[MAX_PATH];
	char			link_path[MAX_PATH];
	int				is_device;
	int				file_ok;
	struct stat		stats;
}	t_file;

int		file_count(t_data *info, const char *name);
int		return_major_or_minor(int rdev, int option);
t_file	*read_dir_stream(t_data *info, const char *name, int i, int f_count);
void	ch_error(char c);
void	file_no_exist(char *str);
void	ls_driver(t_data *info, char *name);
void	ls_recursive(t_data *info, const char *name, int i);
void	ls_with_flags(t_data *info, const char *path);
void	no_directory_access(char *name);
void	no_flags(t_data *info, const char *path);
void	primary_checks(char **str, int args, t_data *info);
void	print_driver(t_file *arr, t_data *info, int f_count);
void	print_file_size(struct stat *stats);
void	print_links_nbr(struct stat *stats);
void	print_mod_time(struct stat *stats);
void	print_rights(struct stat *stats, t_file *arr);
void	print_users(struct stat *stats);
void	sort_driver(t_file *arr, t_data *info, int f_count);
void	space_after_nbr(int nbr);
void	store_and_process_arguments(char **string, t_data *info);
void	write_args_long(t_file arr);
void	write_long_output(t_file *arr, int f_count, int i);


/*
**	ls_sort.c
*/
void	sort_struct_ascending(t_file *arr, int n);
void	sort_struct_reverse(t_file *arr, int end);
void	sort_struct_time(t_file *arr, int n);

/*
**	ls_utils.c
*/
void	allocation_check(t_data *info, t_file *arr, char *ft_name);
void	count_files_and_directories(t_file *arr, t_data *info, int i);
void	print_from_string(char *str, int start, int n);
void	print_short(t_file *arr, int f_count);
void	space_after_str(char *str);





#endif
