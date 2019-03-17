/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:36:55 by ichyzh            #+#    #+#             */
/*   Updated: 2018/04/25 16:36:57 by ichyzh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <locale.h>
# include <inttypes.h>

# define BLACK		"\e[0;30m"
# define RED		"\e[0;31m"
# define GREEN		"\e[0;32m"
# define BLUE		"\e[0;34m"
# define YELLOW		"\e[0;33m"
# define PURPLE		"\e[0;35m"
# define CYAN		"\e[0;36m"
# define WHITE		"\e[0;37m"
# define EOC		"\e[0m"

# define BBLACK		"\e[40m"
# define BRED		"\e[41m"
# define BGREEN		"\e[42m"
# define BBLUE		"\e[44m"
# define BYELLOW	"\e[43m"
# define BPURPLE	"\e[45m"
# define BCYAN		"\e[46m"
# define BWHITE		"\e[47m"

typedef	struct	s_spec
{
	char		flag[5];
	ssize_t		width;
	char		size[2];
	ssize_t		prec;
	char		conv;
	ssize_t		i;
}				t_spec;

int				ft_atoi(const char *nb);
ssize_t			ft_get_int_len(ssize_t n);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa(ssize_t n);
int				ft_isdigit(int c);
int				ft_isspace(int c);
void			ft_del_mas(char **arr);
char			*ft_strnstr(const char *s1, const char *s2, size_t l);
char			**ft_strsplit(char const *str, char d);
int				ft_atoi_base(const char *str, int str_base);
char			*ft_uitoa_base(size_t n, int base, char letter);
size_t			ft_get_numbase_len(size_t n, int base);
char			*ft_strn_char_new(ssize_t size, char c);
size_t			ft_wstrlen(wchar_t *str);
size_t			ft_pwstrlen(wchar_t *str, size_t prec);
size_t			ft_wchar_size(wchar_t c);
char			*megastrjoin(char *s1, char *s2, char *s3);
size_t			print_text(const char *fmt, ssize_t i);
int				ft_printf(const char *format, ...);
size_t			check_and_print(const char *fmt, va_list ap);
ssize_t			check_for_print(t_spec list, va_list ap);
t_spec			create_list(void);
char			*check_prec(t_spec list, ssize_t num);
void			read_spec(const char *fmt, ssize_t i, va_list ap, t_spec *sp);
void			read_flags(const char *fmt, t_spec *sp);
void			read_size(const char *fmt, t_spec *sp, va_list ap);
void			read_modif(const char *fmt, t_spec *sp);
void			read_prec(const char *fmt, t_spec *sp, va_list ap);
ssize_t			check_d(t_spec list, ssize_t num);
ssize_t			ft_invoker(ssize_t num, t_spec list);
char			*check_prefix(t_spec list, ssize_t num,
					char *padding, char *value);
char			*check_padding(t_spec list, ssize_t num, char *value);
size_t			check_o(t_spec list, size_t num);
size_t			ft_invoker_o(size_t num, t_spec list);
char			*check_padding_o(t_spec list, char *value);
char			*check_prefix_o(t_spec list, char *padding, char *value);
char			*check_prec_o(t_spec list, size_t num);
ssize_t			check_u(t_spec list, ssize_t num);
char			*check_prec_u(t_spec list, ssize_t num);
char			*check_prefix_u(t_spec list, char *padding, char *value);
char			*check_padding_u(t_spec list, char *value);
ssize_t			ft_invoker_u(ssize_t num, t_spec list);
size_t			check_x(t_spec list, size_t num);
size_t			ft_invoker_x(size_t num, t_spec list);
char			*check_prec_x(t_spec list, size_t num);
char			*check_prefix_x(t_spec list, char *padding,
					char *value, size_t num);
char			*check_padding_x(t_spec list, size_t num, char *value);
size_t			check_c(t_spec list, char c);
char			*check_padding_c(t_spec list);
void			write_value_c(t_spec list, char c, char *padd);
size_t			check_lc(t_spec list, wchar_t c);
void			write_value_lc(t_spec list, int *num, char *padd, size_t size);
char			*check_padding_lc(t_spec list, wchar_t c);
int				*get_lc(char *value, size_t i);
char			*make_mask(size_t i);
char			*write_mask(char *mask, char *value);
size_t			check_s(t_spec list, char *str);
size_t			write_value_s(t_spec list, char *str, char *padd);
char			*check_padding_s(t_spec list, char *str);
char			*check_prec_s(t_spec list, char *str);
size_t			check_ls(t_spec list, wchar_t *str);
size_t			write_value_ls(t_spec list, wchar_t *str,
					char *padd, size_t bytes);
char			*check_padding_ls(t_spec list, wchar_t *str);
size_t			printwstr(wchar_t *wstr, t_spec list, size_t size);
void			ft_color(const char *fmt, ssize_t *i);
void			ft_print_color(ssize_t *i, char *str, size_t size);
void			ft_print_bcolor(const char *fmt, ssize_t *i);

#endif
