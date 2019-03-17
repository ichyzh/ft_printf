/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	check_u(t_spec list, ssize_t num)
{
	char	*prefix;
	char	*padding;
	char	*value;
	size_t	len;

	num = ft_invoker_u(num, list);
	value = check_prec_u(list, num);
	padding = check_padding_u(list, value);
	prefix = check_prefix_u(list, padding, value);
	len = ft_strlen(prefix);
	write(1, prefix, len);
	free(prefix);
	free(padding);
	free(value);
	return (len);
}

ssize_t	ft_invoker_u(ssize_t num, t_spec list)
{
	if (ft_strncmp(list.size, "h*", 2) == 0 && list.conv != 'U')
		return ((unsigned short int)num);
	if (ft_strncmp(list.size, "hh", 2) == 0)
	{
		if (list.conv == 'U')
			return ((long)num);
		return ((unsigned char)num);
	}
	if (ft_strncmp(list.size, "l*", 2) == 0 || list.conv == 'U')
		return ((unsigned long)num);
	if (ft_strncmp(list.size, "ll", 2) == 0)
		return ((long long int)num);
	if (ft_strncmp(list.size, "j*", 2) == 0)
		return ((intmax_t)num);
	if (ft_strncmp(list.size, "z*", 2) == 0)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

char	*check_prec_u(t_spec list, ssize_t num)
{
	char	*zero;
	char	*tmp;
	char	*value;

	if (list.prec == 0 && num == 0)
		return (ft_strdup(""));
	value = ft_uitoa_base(num, 10, 0);
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

char	*check_prefix_u(t_spec list, char *padding, char *value)
{
	if (list.flag[0] == '-')
		return (ft_strjoin(value, padding));
	return (ft_strjoin(padding, value));
}

char	*check_padding_u(t_spec list, char *value)
{
	char sign;

	if (list.flag[2] == '0' && list.width != 0)
		sign = '0';
	else
		sign = ' ';
	if (list.prec != -1 && list.prec < list.width)
		sign = ' ';
	if (((ssize_t)ft_strlen(value) > list.width) || list.width == 0)
	{
		return (ft_strdup(""));
	}
	return (ft_strn_char_new(list.width - ft_strlen(value), sign));
}
