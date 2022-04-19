/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:53:43 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/19 16:05:45 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_data	*a_to_z_sort(t_data *to_sort, int n)
{
	int		i;
	int 	j;
	t_data	temp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(to_sort[i].f_name, to_sort[j].f_name) > 0)
			{
				temp = to_sort[i];
				to_sort[i] = to_sort[j];
				to_sort[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (to_sort);
}

t_data	*sort_driver(t_data *to_sort, t_args *args)
{
	if (args->flags[1] == 1)
		return (a_to_z_sort(to_sort, to_sort->count));
	else if (args->flags[2] == 1)
		return(to_sort);
	else
	{
		ft_putendl("sort by other means");
		return (to_sort);
	}
}
