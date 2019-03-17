/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_o(t_spec list, size_t num)
{
	char	*prefix;
	char	*padding;
	char	*value;
	size_t	len;

	num = ft_invoker_o(num, list);
	value = check_prec_o(list, num);
	padding = check_padding_o(list, value);
	prefix = check_prefix_o(list, padding, value);
	len = ft_strlen(prefix);
	write(1, prefix, len);
	free(prefix);
	free(padding);
	free(value);
	return (len);
}

size_t	ft_invoker_o(size_t num, t_spec list)
{
	if (ft_strncmp(list.size, "h*", 2) == 0)
	{
		if (list.conv == 'O')
			return ((long)num);
		return ((unsigned short)num);
	}
	if (ft_strncmp(list.size, "hh", 2) == 0)
	{
		if (list.conv == 'O')
			return ((long)num);
		return ((unsigned char)num);
	}
	if (ft_strncmp(list.size, "l*", 2) == 0)
		return ((long)num);
	if (ft_strncmp(list.size, "ll", 2) == 0)
		return ((long long)num);
	if (ft_strncmp(list.size, "j*", 2) == 0)
		return ((intmax_t)num);
	if (ft_strncmp(list.size, "z*", 2) == 0 || list.conv == 'O')
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

char	*check_prec_o(t_spec list, size_t num)
{
	char	*zero;
	char	*tmp;
	char	*value;

	if (list.prec == 0 && num == 0 && list.flag[4] == '*')
		return (ft_strdup(""));
	value = ft_uitoa_base(num, 8, 0);
	if (list.flag[4] == '#' && num != 0)
	{
		tmp = ft_strjoin("0", value);
		free(value);
		value = ft_strdup(tmp);
		free(tmp);
	}
	if (list.prec != -1 && list.prec > (ssize_t)ft_strlen(value))
	{
		zero = ft_strn_char_new(list.prec - ft_strlen(value), '0');
		tmp = ft_strjoin(zero, value);
		free(value);
		free(zero);
		return (tmp);
	}
	return (value);
}

char	*check_prefix_o(t_spec list, char *padding, char *value)
{
	if (list.flag[0] == '-')
		return (ft_strjoin(value, padding));
	return (ft_strjoin(padding, value));
}

char	*check_padding_o(t_spec list, char *value)
{
	if (list.prec > (ssize_t)ft_strlen(value))
		return (ft_strn_char_new(list.prec - ft_strlen(value), '0'));
	if (((ssize_t)ft_strlen(value) > list.width))
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.width != 0 && list.flag[0] == '*')
	{
		if (list.prec != -1 && list.prec < list.width)
			return (ft_strn_char_new(list.width - ft_strlen(value), ' '));
		return (ft_strn_char_new(list.width - ft_strlen(value), '0'));
	}
	return (ft_strn_char_new(list.width - ft_strlen(value), ' '));
}
