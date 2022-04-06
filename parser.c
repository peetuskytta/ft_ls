/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:04:10 by pskytta           #+#    #+#             */
/*   Updated: 2022/04/06 07:37:54 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*allocate(char **str, int i)
{
	t_ls	*input;

	input = ft_memalloc(sizeof(t_ls));
	while (str[i] != '\0')
	{
		if (i == 1)
			input->command = ft_strdup(str[i]);
		if (i <= 6)
		{
			if (ft_strchr(str[i], '-') != NULL)
				input->flags = ft_strdup(str[i]);
		}
		else
		{
			
			input->files = ft_strdup(str[i]);
		}
	}
	return (input);
}
