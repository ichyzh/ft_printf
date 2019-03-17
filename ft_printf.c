/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spec		create_list(void)
{
	t_spec list;

	list.flag[0] = '*';
	list.flag[1] = '*';
	list.flag[2] = '*';
	list.flag[3] = '*';
	list.flag[4] = '*';
	list.width = 0;
	list.size[0] = '*';
	list.size[1] = '*';
	list.prec = -1;
	list.conv = '*';
	list.i = 0;
	return (list);
}

size_t		print_text(const char *fmt, ssize_t i)
{
	write(1, &(fmt[i]), 1);
	return (1);
}

ssize_t		check_for_print(t_spec list, va_list ap)
{
	if (list.conv == 'd' || list.conv == 'D' || list.conv == 'i')
		return (check_d(list, va_arg(ap, ssize_t)));
	if (list.conv == 'o' || list.conv == 'O')
		return (check_o(list, va_arg(ap, size_t)));
	if (list.conv == 'u' || list.conv == 'U')
		return (check_u(list, va_arg(ap, ssize_t)));
	if (list.conv == 'x' || list.conv == 'X' || list.conv == 'p')
		return (check_x(list, va_arg(ap, size_t)));
	if (list.conv == 'c' || list.conv == 'C')
		return (check_lc(list, va_arg(ap, wchar_t)));
	if (list.conv == 's')
		return (check_s(list, va_arg(ap, char *)));
	if (list.conv == 'S' || list.conv == 's')
		return (check_ls(list, va_arg(ap, wchar_t *)));
	if (list.conv != '*')
		return (check_c(list, list.conv));
	return (0);
}

size_t		check_and_print(const char *fmt, va_list ap)
{
	ssize_t	i;
	t_spec	sp;
	size_t	k;
	size_t	len;

	i = -1;
	k = 0;
	len = 0;
	while (fmt[++i] != '\0')
	{
		if (fmt[i] == '{')
			ft_color(fmt, &i);
		if (fmt[i] == '%')
		{
			sp = create_list();
			read_spec(fmt, i + 1, ap, &sp);
			if ((size_t)(i = sp.i) > ft_strlen(fmt) - 1)
				return (len + k);
			len += check_for_print(sp, ap);
		}
		else
			k += print_text(fmt, i);
	}
	return ((int)(len + k));
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;

	va_start(ap, fmt);
	len = check_and_print(fmt, ap);
	va_end(ap);
	return ((int)len);
}
