# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 20:45:31 by itoudji           #+#    #+#              #
#    Updated: 2023/11/30 21:03:48 by itoudji          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
CFLAGS	:=	-Wall -Wextra -Werror
LDFLAGS	:=	-Llibft -lft

RM		:=	rm -f
SRC		:=	ft_printf.c \
			utils.c \
			ft_print_1.c \
			ft_print_2.c \

OBJ	:=	$(SRC:.c=.o)

%.o:		%.c
				$(CC) $(CFLAGS) -Ilibft $< -c

$(NAME):	$(OBJ)
				$(MAKE) -C libft bonus
				cp libft/libft.a $(NAME)
				$(AR) rcs $(NAME) $(OBJ)

all:		$(NAME)

clean:
				$(MAKE) -C libft clean
				$(RM) *.o */*.o */*/*.o

fclean:		clean
				$(MAKE) -C libft fclean
				$(RM) *.a *.out

re:			fclean all
