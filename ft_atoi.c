/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:26:14 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:27:48 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *nb)
{
	size_t		i;
	long long	neg;
	long long	res;

	neg = 1;
	res = 0;
	i = 0;
	while (ft_isspace(nb[i]))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		neg = (nb[i] == '-') ? -1 : 1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		if (res * 10 + nb[i] - '0' < res)
			return (neg == 1 ? -1 : 0);
		res = res * 10 + (nb[i] - '0');
		i++;
	}
	return (res * neg);
}
