/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/14 10:57:05 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <unistd.h>
# include <dirent.h>

typedef struct s_data
{
	char	*f_name;
	int		type;
	int		name_len;
	int		count;
	int		flags[5];
}	t_data;

t_data	*a_to_z_sort(t_data *to_sort, int n);
t_data	*sort_driver(t_data *to_sort);
int		argument_check(int count, char **str);
int		file_and_directory_count(const char *dirname, int count);
void	error_prints(int n, char *str);
void	ls_with_flags(t_data *arr_of_s, char **string);
void	only_ls(t_data *arr_of_s);
void	print_double(char **str);

#endif
