/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:45:58 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/07 17:22:35 by pskytta          ###   ########.fr       */
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
int		argument_check(int count, char **str);
int		file_count(const char *dirname, int count);
t_data	*list_files(const char *dirname, int i, int count);
void	arg_errors(int n, char *str);
void	ls_check(char *str);
void	print_2ws(const char *str);
void	print_col(const char *str);
void	print_double(char **str);

#endif
