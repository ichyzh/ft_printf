/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_get_numbase_len(size_t n, int base)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_uitoa_base(size_t n, int base, char letter)
{
	char	*str;
	size_t	l;
	size_t	m;

	m = n;
	l = ft_get_numbase_len(m, base);
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	str[l] = '\0';
	if (n == 0)
		str[0] = '0';
	while (m)
	{
		if (((size_t)m % base) >= 10)
		{
			str[--l] = letter + (m % base) - 10;
			m /= base;
		}
		else
		{
			str[--l] = m % base + '0';
			m /= base;
		}
	}
	return (str);
}

size_t	ft_wchar_size(wchar_t c)
{
	if (c <= 127)
		return (1);
	if (c >= 128 && c <= 2047)
		return (2);
	if (c >= 2048 && c <= 65535)
		return (3);
	if (c >= 65536 && c <= 2097151)
		return (4);
	else
		return (0);
}

size_t	printwstr(wchar_t *wstr, t_spec list, size_t size)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (wstr[i] == '\0')
		return (0);
	while ((len + (ssize_t)ft_wchar_size(wstr[i])) <= size)
	{
		len += check_lc(list, wstr[i]);
		i++;
	}
	return (len);
}

char	*make_mask(size_t i)
{
	if (i == 1)
		return (ft_strdup("0xxxxxxx"));
	else if (i == 2)
		return (ft_strdup("110xxxxx 10xxxxxx"));
	else if (i == 3)
		return (ft_strdup("1110xxxx 10xxxxxx 10xxxxxx"));
	else if (i == 4)
		return (ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"));
	else
		return (ft_strdup(""));
}
