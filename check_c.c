/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_c(t_spec list, char c)
{
	char	*padding;
	size_t	len;

	padding = check_padding_c(list);
	write_value_c(list, c, padding);
	len = ft_strlen(padding);
	free(padding);
	return (len + 1);
}

void	write_value_c(t_spec list, char c, char *padd)
{
	if (list.flag[0] == '-')
	{
		write(1, &c, 1);
		write(1, padd, ft_strlen(padd));
	}
	else
	{
		write(1, padd, ft_strlen(padd));
		write(1, &c, 1);
	}
}

char	*check_padding_c(t_spec list)
{
	if (list.width == 0)
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.flag[0] != '-')
		return (ft_strn_char_new(list.width - 1, '0'));
	return (ft_strn_char_new(list.width - 1, ' '));
}
