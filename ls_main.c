/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:49:13 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/16 15:17:06 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*store_arguments(t_data *to_save, char **str)
{
	to_save = store_flags(to_save, str, 2);
	to_save = store_rest(to_save, str, to_save->flag_args + 2);
	return (to_save);
}

int	main(int argc, char *argv[])
{
	t_data	*arr_of_s;

	arr_of_s = ft_memalloc(sizeof(t_data));
	arr_of_s->arg_count = argc - 2;
	if (argument_check(argc, argv) == 1)
	{
		arr_of_s = only_ls(arr_of_s);
		print_ls(arr_of_s, 0);
	}
	else if (argument_check(argc, argv) == 2)
	{
		ls_with_extra(arr_of_s, argv);
	}
	else
		error_prints(1, "usage: ./ft_ls <ls> <flags> <filename>");
	free(arr_of_s);
	ft_putendl("");
	return (0);
}
