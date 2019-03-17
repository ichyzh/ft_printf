/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:08:47 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 15:08:52 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t l)
{
	size_t i;
	size_t j;
	size_t n;

	i = 0;
	n = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (s1[i] && i < l)
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != '\0' && (i + j) < l)
			j++;
		if (n == j)
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
