/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:11:59 by ichyzh            #+#    #+#             */
/*   Updated: 2017/11/21 16:12:40 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_word_length(const char *s, char d)
{
	int i;

	i = 0;
	while (s[i] != d && s[i])
	{
		i++;
	}
	return (i);
}

int			ft_word_count(const char *s, char d)
{
	int i;
	int count;
	int word;

	i = 0;
	count = 0;
	while (s[i])
	{
		word = 0;
		while (s[i] && s[i] == d)
			i++;
		while (s[i] && s[i] != d)
		{
			i++;
			word = 1;
		}
		if (word == 1)
			count++;
	}
	return (count);
}

static char	**ft_splitinn(char **s, char const *str, char d)
{
	int i;
	int k;
	int j;
	int n;

	i = -1;
	j = 0;
	while (++i < ft_word_count(str, d))
	{
		while (str[j] == d)
			j++;
		if (str[j])
		{
			n = ft_word_length(&str[j], d);
			if (!(s[i] = (char*)malloc(sizeof(char) * (n + 1))))
				return (NULL);
			s[i][n] = '\0';
			k = 0;
			while (k < n)
				s[i][k++] = str[j++];
		}
	}
	s[i] = NULL;
	return (s);
}

char		**ft_strsplit(char const *str, char d)
{
	char	**s;

	if (!str)
		return (NULL);
	s = NULL;
	if (!(s = (char**)malloc(sizeof(char*) *
		(ft_word_count(str, d) + 1))))
		return (NULL);
	s = ft_splitinn(s, str, d);
	return (s);
}
