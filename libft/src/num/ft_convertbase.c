/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:25:27 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:03:23 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_len(long long nb, int baselen)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= baselen;
		i++;
	}
	return (i);
}

char	*ft_nbtobase(long long nb, const char *base)
{
	int		base_len;
	int		i;
	char	*nbr;

	base_len = ft_strlen(base);
	i = get_nb_len(nb, base_len);
	nbr = ft_calloc(i + 1, sizeof(char));
	if (!nbr)
		return (NULL);
	if (nb < 0)
	{
		nbr[0] = '-';
		nb *= -1;
	}
	nbr[i] = '\0';
	i--;
	while (nb >= base_len)
	{
		nbr[i] = base[nb % base_len];
		nb /= base_len;
		i--;
	}
	nbr[i] = base[nb];
	return (nbr);
}

long long	ft_basetonb(char *nbr, const char *base)
{
	long long	nb;
	int			sign;
	int			base_len;

	nb = 0;
	sign = 1;
	base_len = ft_strlen(base);
	if (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = -1;
		nbr++;
	}
	while (*nbr && ft_strchr(base, *nbr))
	{
		nb *= base_len;
		nb += (ft_strchr(base, *nbr) - base);
		nbr++;
	}
	return (nb * sign);
}

char	*ft_convert_base(char *nbr, const char *base_from, const char *base_to)
{
	long long	nb;
	char		*conv;

	nb = ft_basetonb(nbr, base_from);
	conv = ft_nbtobase(nb, base_to);
	return (conv);
}
