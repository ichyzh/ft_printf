/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_ls(t_spec list, wchar_t *str)
{
	char	*padding;
	size_t	len;
	size_t	size;

	if (!str)
		str = L"(null)";
	size = ft_wstrlen(str);
	padding = check_padding_ls(list, str);
	if (list.prec != -1 && list.prec <= (ssize_t)size)
	{
		if (list.prec < (ssize_t)ft_wchar_size(str[0]))
			size = 0;
		else
			size = (size_t)list.prec;
	}
	len = write_value_ls(list, str, padding, size);
	free(padding);
	return (len);
}

size_t	write_value_ls(t_spec list, wchar_t *str, char *padd, size_t size)
{
	ssize_t len;

	if (list.flag[0] == '-')
	{
		list = create_list();
		len = printwstr(str, list, size);
		write(1, padd, ft_strlen(padd));
	}
	else
	{
		list = create_list();
		write(1, padd, ft_strlen(padd));
		len = printwstr(str, list, size);
	}
	return (ft_strlen(padd) + len);
}

size_t	ft_wstrlen(wchar_t *str)
{
	size_t len;

	len = 0;
	while (*str != '\0')
	{
		len += ft_wchar_size(*str);
		str++;
	}
	return (len);
}

size_t	ft_pwstrlen(wchar_t *str, size_t prec)
{
	size_t len;

	len = 0;
	while (*str != '\0' && (prec >= len + ft_wchar_size(*str)))
	{
		len += ft_wchar_size(*str);
		str++;
	}
	return (len);
}

char	*check_padding_ls(t_spec list, wchar_t *str)
{
	char	sign;
	size_t	size;

	size = 0;
	if (list.flag[2] == '0' && list.flag[0] != '-')
		sign = '0';
	else
		sign = ' ';
	if (list.width == 0)
		return (ft_strdup(""));
	if ((ssize_t)ft_wchar_size(str[0]) > list.width)
		ft_strn_char_new(list.width, sign);
	if (list.prec != -1)
	{
		size = (size_t)list.prec;
		if ((list.prec < (ssize_t)ft_wchar_size(str[0])))
			return (ft_strn_char_new(list.width, sign));
		return (ft_strn_char_new(list.width - ft_pwstrlen(str, size), sign));
	}
	return (ft_strn_char_new(list.width - ft_wstrlen(str), sign));
}
