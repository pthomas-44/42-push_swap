/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:20:15 by pthomas           #+#    #+#             */
/*   Updated: 2021/10/02 15:33:34 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	basecheck(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[j] == '-' || base[j] == '+'
				|| !ft_isprint(base[j]))
				return (1);
			j++;
		}
		i++;
	}
	if (j < 2)
		return (1);
	else
		return (0);
}

static int	base_to_i(char *nbr, char *base_from)
{
	int		i;
	int		j;
	long	nb;
	int		sign;
	int		base_len;

	i = 0;
	nb = 0;
	sign = 1;
	base_len = ft_strlen(base_from);
	if (nbr[i] == '-')
		sign = -1;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i] && ft_strchr(base_from, nbr[i]))
	{
		j = 0;
		while (base_from[j] && base_from[j] != nbr[i])
			j++;
		nb *= base_len;
		nb += j;
		i++;
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	long	nb;
	char	*conv;

	i = 0;
	if (basecheck(base_from) != 0 || basecheck(base_to) != 0)
		return (0);
	nb = base_to_i(nbr, base_from);
	conv = ft_nbtobase(nb, base_to);
	if (!conv)
		return (0);
	return (conv);
}
