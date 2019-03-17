/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_x(t_spec list, size_t num)
{
	char	*prefix;
	char	*padding;
	char	*value;
	size_t	len;

	num = ft_invoker_x(num, list);
	value = check_prec_x(list, num);
	padding = check_padding_x(list, num, value);
	prefix = check_prefix_x(list, padding, value, num);
	len = ft_strlen(prefix);
	write(1, prefix, len);
	free(prefix);
	free(padding);
	free(value);
	return (len);
}

size_t	ft_invoker_x(size_t num, t_spec list)
{
	if (ft_strncmp(list.size, "h*", 2) == 0)
		return ((unsigned short)num);
	if (ft_strncmp(list.size, "hh", 2) == 0)
		return ((unsigned char)num);
	if (ft_strncmp(list.size, "l*", 2) == 0)
		return ((long int)num);
	if (ft_strncmp(list.size, "ll", 2) == 0)
		return ((long long int)num);
	if (ft_strncmp(list.size, "j*", 2) == 0)
		return ((uintmax_t)num);
	if ((ft_strncmp(list.size, "z*", 2) == 0) || list.conv == 'p')
		return ((size_t)num);
	else
		return ((unsigned int)num);
}

char	*check_prec_x(t_spec list, size_t num)
{
	char *zero;
	char *tmp;
	char *value;

	if (list.prec == 0 && num == 0)
		return (ft_strdup(""));
	if (list.conv == 'X')
		value = ft_uitoa_base(num, 16, 65);
	else
		value = ft_uitoa_base(num, 16, 97);
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

char	*check_prefix_x(t_spec list, char *padding, char *value, size_t num)
{
	char *prefix;

	prefix = "";
	if ((list.flag[4] == '#' && num != 0) || list.conv == 'p')
	{
		if (list.conv == 'X')
			prefix = "0X";
		if (list.conv == 'x' || list.conv == 'p')
			prefix = "0x";
	}
	if (list.flag[0] == '-' || (list.conv == 'p' && list.flag[2] == '0'))
		return (megastrjoin(prefix, value, padding));
	if ((list.flag[4] == '#' && list.flag[2] != '0') || list.conv == 'p')
		return (megastrjoin(padding, prefix, value));
	if (list.prec != -1 && list.prec < list.width)
		return (megastrjoin(padding, prefix, value));
	return (megastrjoin(prefix, padding, value));
}

char	*check_padding_x(t_spec list, size_t num, char *value)
{
	char sign;

	if (((ssize_t)ft_strlen(value) >= list.width) || list.width == 0)
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.flag[0] == '*')
		sign = '0';
	else
		sign = ' ';
	if (list.prec != -1 && list.prec < list.width)
		sign = ' ';
	if ((list.flag[4] == '#' && num != 0) || list.conv == 'p')
		return (ft_strn_char_new(list.width - ft_strlen(value) - 2, sign));
	return (ft_strn_char_new(list.width - ft_strlen(value), sign));
}
