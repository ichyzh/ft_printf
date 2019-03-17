/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_flags(const char *fmt, t_spec *sp)
{
	while ((ft_strchr("-+0# ", fmt[sp->i]) != NULL) && fmt[sp->i] != '\0')
	{
		if (fmt[sp->i] == '+')
			sp->flag[1] = '+';
		if (fmt[sp->i] == '0')
			sp->flag[2] = '0';
		if (fmt[sp->i] == ' ')
			sp->flag[3] = ' ';
		if (fmt[sp->i] == '#')
			sp->flag[4] = '#';
		if (fmt[sp->i] == '-')
			sp->flag[0] = '-';
		sp->i++;
	}
}

void	read_size(const char *fmt, t_spec *sp, va_list ap)
{
	ssize_t	k;

	while (ft_isdigit(fmt[sp->i]) || fmt[sp->i] == '*')
	{
		if (ft_isdigit(fmt[sp->i]))
		{
			k = sp->i;
			while (ft_isdigit(fmt[k]))
				k++;
			sp->width = ft_atoi(&fmt[sp->i]);
			sp->i = k - 1;
		}
		if (fmt[sp->i] == '*')
		{
			sp->width = va_arg(ap, int);
			if (sp->width < 0)
			{
				sp->flag[0] = '-';
				sp->width *= -1;
			}
		}
		sp->i++;
	}
}

void	read_modif(const char *fmt, t_spec *sp)
{
	while (fmt[sp->i] != '\0' && ft_strchr("hljz", fmt[sp->i]) != NULL)
	{
		if (sp->size[0] != '*')
		{
			sp->i++;
			return ;
		}
		sp->size[0] = fmt[sp->i];
		if ((fmt[sp->i] == 'h' && fmt[sp->i + 1] == 'h') ||
			(fmt[sp->i] == 'l' && fmt[sp->i + 1] == 'l'))
			sp->size[1] = fmt[sp->i];
		sp->i++;
	}
}

void	read_prec(const char *fmt, t_spec *sp, va_list ap)
{
	ssize_t k;

	k = 0;
	if (fmt[sp->i] == '.')
	{
		k = ++sp->i;
		if (fmt[sp->i] == '*')
		{
			sp->prec = va_arg(ap, int);
			if (sp->prec < 0)
				sp->prec = -1;
			k++;
		}
		else
		{
			while (ft_isdigit(fmt[k]))
				k++;
			sp->prec = ft_atoi(&fmt[sp->i]);
		}
		sp->i = k;
	}
}

void	read_spec(const char *fmt, ssize_t i, va_list ap, t_spec *sp)
{
	sp->i = i;
	if (!fmt[i])
		return ;
	read_flags(fmt, sp);
	read_size(fmt, sp, ap);
	read_modif(fmt, sp);
	read_prec(fmt, sp, ap);
	if (ft_strchr("-+0# zhlj#.", fmt[sp->i]) != NULL)
		read_spec(fmt, sp->i, ap, sp);
	if (fmt[sp->i] != '\0')
		sp->conv = fmt[sp->i];
}
