/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:50:14 by pthomas           #+#    #+#             */
/*   Updated: 2021/10/02 15:33:31 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return ((int)sign * nb);
}

long	ft_atol(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - 48;
		str++;
	}
	return (sign * nb);
}

static int	nbrlen(long long nb, int baselen)
{
	unsigned int	i;

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

char	*ft_nbtobase(long long nb, char *base)
{
	int		i;
	int		base_len;
	char	*nbr;

	base_len = ft_strlen(base);
	i = nbrlen(nb, base_len);
	nbr = malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (0);
	if (nb < 0)
	{
		nbr[0] = '-';
		nb = -nb;
	}
	nbr[i--] = 0;
	while (nb >= base_len)
	{
		nbr[i--] = base[nb % base_len];
		nb /= base_len;
	}
	nbr[i] = base[nb];
	return (nbr);
}
