# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichyzh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 16:23:53 by ichyzh            #+#    #+#              #
#    Updated: 2018/04/19 16:23:54 by ichyzh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
		read_spec.c \
		check_d.c \
		check_o.c \
		check_u.c \
		check_x.c \
		check_c.c \
		check_s.c \
		check_lc.c \
		check_ls.c \
		ft_color.c \
		ft_itoa.c \
		helper.c \
		ft_atoi.c \
		ft_atoi_base.c \
		megastrjoin.c \
		ft_strn_char_new.c \
		ft_del_mas.c \
		ft_strsplit.c \
		ft_isdigit.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strsub.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strchr.c \
		ft_isspace.c \
		ft_strnstr.c
		
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re:  fclean all