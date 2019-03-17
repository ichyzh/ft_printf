/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_s(t_spec list, char *str)
{
	char	*padding;
	size_t	len;
	char	*s;

	if (ft_strncmp(list.size, "l*", 2) == 0)
		return (check_ls(list, (wchar_t *)str));
	if (!str)
		str = "(null)";
	s = check_prec_s(list, str);
	padding = check_padding_s(list, s);
	len = write_value_s(list, s, padding);
	free(padding);
	free(s);
	return (len);
}

char	*check_prec_s(t_spec list, char *str)
{
	if (list.prec != -1)
	{
		return (ft_strsub(str, 0, (size_t)list.prec));
	}
	return (ft_strdup(str));
}

size_t	write_value_s(t_spec list, char *str, char *padd)
{
	if (list.flag[0] == '-')
	{
		write(1, str, ft_strlen(str));
		write(1, padd, ft_strlen(padd));
	}
	else
	{
		write(1, padd, ft_strlen(padd));
		write(1, str, ft_strlen(str));
	}
	return (ft_strlen(padd) + ft_strlen(str));
}

char	*check_padding_s(t_spec list, char *str)
{
	if (list.width == 0)
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.flag[0] != '-')
		return (ft_strn_char_new(list.width - ft_strlen(str), '0'));
	return (ft_strn_char_new(list.width - ft_strlen(str), ' '));
}
