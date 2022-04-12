/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/12 21:50:42 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>
# include <errno.h>

typedef struct s_data
{
	char	*f_name;
	int		type;
	int		name_len;
	int		count;
	int		flags[5];
}	t_data;

int		argument_check(int count, char **str);
int		file_and_directory_count(const char *dirname, int count);
t_data	*list_files_and_directories(const char *dirname, int i, int count);
void	error_prints(int n, char *str);
void	ls_with_flags(t_data *arr_of_s, char **string);
void	only_ls(t_data *arr_of_s);
void	print_double(char **str);

//void	bubble_sort_a_to_z(t_data *st, int size);

#endif
