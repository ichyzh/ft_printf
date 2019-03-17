/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megastrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*megastrjoin(char *s1, char *s2, char *s3)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(s1, s2);
	str2 = ft_strjoin(str, s3);
	free(str);
	return (str2);
}
