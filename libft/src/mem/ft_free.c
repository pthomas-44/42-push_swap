/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:13:12 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:11:54 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	(*ptr) = NULL;
}

void	free_array(char ***ptr, size_t size)
{
	size_t	i;

	i = 0;
	if ((*ptr))
	{
		while ((*ptr)[i] || i < size)
		{
			free((*ptr)[i]);
			(*ptr)[i] = NULL;
			i++;
		}
		free((*ptr));
		(*ptr) = NULL;
	}
}
