/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:03:38 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:03:46 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;
	int		i;
	char	t;

	if (!s)
		return (NULL);
	r = (char*)s;
	t = (char)c;
	i = 0;
	while (r[i])
	{
		if (r[i] == t)
			return (r + i);
		i++;
	}
	if (t == '\0')
		return (r + i);
	return (NULL);
}
