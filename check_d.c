/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	check_d(t_spec list, ssize_t num)
{
	char	*prefix;
	char	*padding;
	char	*value;
	size_t	len;

	num = ft_invoker(num, list);
	value = check_prec(list, num);
	padding = check_padding(list, num, value);
	prefix = check_prefix(list, num, padding, value);
	len = ft_strlen(prefix);
	write(1, prefix, len);
	free(prefix);
	free(padding);
	free(value);
	return (len);
}

ssize_t	ft_invoker(ssize_t num, t_spec list)
{
	if (ft_strncmp(list.size, "h*", 2) == 0)
	{
		if (list.conv == 'D')
			return ((long)num);
		return ((short)num);
	}
	if (ft_strncmp(list.size, "hh", 2) == 0)
	{
		if (list.conv == 'D')
			return ((long)num);
		return ((char)num);
	}
	if (ft_strncmp(list.size, "l*", 2) == 0)
		return ((long int)num);
	if (ft_strncmp(list.size, "ll", 2) == 0)
		return ((long long int)num);
	if (ft_strncmp(list.size, "j*", 2) == 0)
		return ((intmax_t)num);
	if (ft_strncmp(list.size, "z*", 2) == 0 || list.conv == 'D')
		return ((size_t)num);
	else
		return ((int)num);
}

char	*check_prec(t_spec list, ssize_t num)
{
	char *zero;
	char *tmp;
	char *value;

	if (list.prec == 0 && num == 0)
		return (ft_strdup(""));
	value = ft_itoa(num);
	if (list.prec != -1)
	{
		if (list.prec > (ssize_t)ft_strlen(value))
		{
			zero = ft_strn_char_new(list.prec - ft_strlen(value), '0');
			tmp = ft_strjoin(zero, value);
			free(value);
			free(zero);
			return (tmp);
		}
	}
	return (value);
}

char	*check_prefix(t_spec list, ssize_t num, char *padding, char *value)
{
	char *prefix;

	prefix = num < 0 ? "-" : "";
	if (list.flag[3] == ' ' && num >= 0)
		prefix = " ";
	if (list.flag[1] == '+' && num >= 0)
		prefix = "+";
	if (list.flag[2] == '0' && list.flag[0] == '*')
	{
		if (list.prec != -1 && list.prec < list.width)
			return (megastrjoin(padding, prefix, value));
		return (megastrjoin(prefix, padding, value));
	}
	if (list.flag[0] == '-')
		return (megastrjoin(prefix, value, padding));
	return (megastrjoin(padding, prefix, value));
}

char	*check_padding(t_spec list, ssize_t num, char *value)
{
	char sign;

	if ((ssize_t)ft_strlen(value) > list.width || list.width == 0)
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.flag[0] == '*')
		sign = '0';
	else
		sign = ' ';
	if (list.prec != -1 && list.prec < list.width)
		sign = ' ';
	if (list.flag[1] == '+' || list.flag[3] == ' ' || num < 0)
		return (ft_strn_char_new(list.width - ft_strlen(value) - 1, sign));
	return (ft_strn_char_new(list.width - ft_strlen(value), sign));
}
