/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:53:43 by pskytta           #+#    #+#             */
/*   Updated: 2022/05/24 09:07:52 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	a_to_z_sort(t_data *to_sort, int n)
{
	int		i;
	int		j;
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
}

void	argument_sort(char **list, int n)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(list[i], list[j]) > 0)
			{
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_by_flag(t_data *arr)
{
	dot_file_count(arr, 0);
	a_to_z_sort(arr, arr->count);
	//if (arr->flags[4] == 1)
		//arr = time_sort(arr, arr->count);
	if (arr->flags[2] == 1)
		arr = reverse_order(arr, arr->count);
}

t_data	*reverse_order(t_data *arr, int n)
{
	int		i;
	t_data	temp;

	i = 0;
	while (i < n/2)
	{
		temp = arr[i];
		arr[i] = arr[n];
		arr[n] = temp;
		n--;
		i++;
	}
	return (arr);
}