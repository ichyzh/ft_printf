/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_color(const char *fmt, ssize_t *i)
{
	if (ft_strnstr(&fmt[*i], "{b", 2) != NULL)
		ft_print_bcolor(fmt, i);
	if (ft_strnstr(&fmt[*i], "{red}", 5) != NULL)
		ft_print_color(i, RED, 5);
	if (ft_strnstr(&fmt[*i], "{eoc}", 5) != NULL)
		ft_print_color(i, EOC, 5);
	if (ft_strnstr(&fmt[*i], "{blue}", 6) != NULL)
		ft_print_color(i, BLUE, 6);
	if (ft_strnstr(&fmt[*i], "{green}", 7) != NULL)
		ft_print_color(i, GREEN, 7);
	if (ft_strnstr(&fmt[*i], "{yellow}", 8) != NULL)
		ft_print_color(i, YELLOW, 8);
	if (ft_strnstr(&fmt[*i], "{black}", 7) != NULL)
		ft_print_color(i, BLACK, 7);
	if (ft_strnstr(&fmt[*i], "{purple}", 8) != NULL)
		ft_print_color(i, PURPLE, 8);
	if (ft_strnstr(&fmt[*i], "{cyan}", 6) != NULL)
		ft_print_color(i, CYAN, 6);
	if (ft_strnstr(&fmt[*i], "{white}", 7) != NULL)
		ft_print_color(i, WHITE, 7);
}

void	ft_print_bcolor(const char *fmt, ssize_t *i)
{
	if (ft_strnstr(&fmt[*i], "{bred}", 6) != NULL)
		ft_print_color(i, BRED, 6);
	if (ft_strnstr(&fmt[*i], "{bblue}", 7) != NULL)
		ft_print_color(i, BBLUE, 7);
	if (ft_strnstr(&fmt[*i], "{bgreen}", 8) != NULL)
		ft_print_color(i, BGREEN, 8);
	if (ft_strnstr(&fmt[*i], "{byellow}", 9) != NULL)
		ft_print_color(i, BYELLOW, 9);
	if (ft_strnstr(&fmt[*i], "{bblack}", 8) != NULL)
		ft_print_color(i, BBLACK, 8);
	if (ft_strnstr(&fmt[*i], "{bpurple}", 9) != NULL)
		ft_print_color(i, BPURPLE, 9);
	if (ft_strnstr(&fmt[*i], "{bcyan}", 7) != NULL)
		ft_print_color(i, BCYAN, 7);
	if (ft_strnstr(&fmt[*i], "{bwhite}", 8) != NULL)
		ft_print_color(i, BWHITE, 8);
}

void	ft_print_color(ssize_t *i, char *str, size_t size)
{
	write(1, str, ft_strlen(str));
	*i += size;
}
