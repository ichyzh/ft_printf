/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_lc(t_spec list, wchar_t c)
{
	char	*padding;
	size_t	len;
	char	*value;
	int		*num;
	size_t	i;

	value = ft_uitoa_base((size_t)c, 2, 0);
	i = ft_wchar_size(c);
	num = get_lc(value, i);
	if (list.conv == 'c' && ft_strncmp(list.size, "l*", 2) != 0)
		return (check_c(list, c));
	padding = check_padding_lc(list, c);
	write_value_lc(list, num, padding, i);
	len = ft_strlen(padding);
	free(padding);
	free(value);
	free(num);
	return (len + i);
}

int		*get_lc(char *value, size_t i)
{
	char	*mask;
	char	*letter;
	char	**split;
	int		*num;
	size_t	j;

	j = 0;
	mask = make_mask(i);
	letter = write_mask(mask, value);
	split = ft_strsplit(letter, ' ');
	if (!(num = (int *)malloc(sizeof(int) * i)))
		return (0);
	while (j < i)
	{
		num[j] = ft_atoi_base(split[j], 2);
		j++;
	}
	ft_del_mas(split);
	free(mask);
	return (num);
}

char	*write_mask(char *mask, char *value)
{
	ssize_t	j;
	ssize_t	i;

	i = ft_strlen(value) - 1;
	j = ft_strlen(mask);
	while (j > 0)
	{
		while (mask[j] == 'x' && i >= 0)
		{
			mask[j] = value[i];
			j--;
			i--;
		}
		j--;
	}
	j = 0;
	while (mask[j] != '\0')
	{
		if (mask[j] == 'x')
			mask[j] = '0';
		j++;
	}
	return (mask);
}

void	write_value_lc(t_spec list, int *num, char *padd, size_t size)
{
	size_t j;

	j = 0;
	if (list.flag[0] == '-')
	{
		while (j < size)
		{
			write(1, &(num[j]), 1);
			j++;
		}
		write(1, padd, ft_strlen(padd));
	}
	else
	{
		write(1, padd, ft_strlen(padd));
		while (j < size)
		{
			write(1, &(num[j]), 1);
			j++;
		}
	}
}

char	*check_padding_lc(t_spec list, wchar_t c)
{
	if (list.width == 0)
		return (ft_strdup(""));
	if (list.flag[2] == '0' && list.flag[0] != '-')
		return (ft_strn_char_new(list.width - ft_wchar_size(c), '0'));
	return (ft_strn_char_new(list.width - ft_wchar_size(c), ' '));
}
