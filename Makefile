# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 14:40:43 by fginja-d          #+#    #+#              #
#    Updated: 2018/09/10 16:03:30 by fginja-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC_FOLDER = src/

SRC_FILES = ft_printf.c ft_printf_decimal.c get_flags.c ft_printf_str.c\
	ft_printf_char.c ft_convert.c ft_putlnbr.c ft_printf_float.c\
	ft_printf_hexa.c ft_printf_octal.c ft_utils.c\

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))

OBJ = $(SRC_FILES:.c=.o)

$(NAME):
	@echo "Compilation en cours..."
	gcc -c $(FLAGS) $(SRC) -L./libft/ -lft
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) générée avec succès"

all:
	$(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
