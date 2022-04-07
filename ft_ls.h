/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/08 01:01:15 by pskytta          ###   ########.fr       */
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
}	t_data;

int		action_check(int n);
t_data	*argument_check(int count, char **str, int *flags);
int		file_count(const char *dirname, int count);
t_data	*list_files(const char *dirname, int i, int count);
void	arg_errors(int n, char *str);
void	ls_check(char **str);
void	flag_check(char **str, int *flags, int i);
void	print_2ws(const char *str);
void	print_col(const char *str);
void	print_double(char **str);
void	print_ls(t_data *to_print, int i);
void	print_ls_a(t_data *to_print, int i);

#endif
