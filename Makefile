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

SRC_FOLDER = src/
LIBFT_FOLDER = libft/

SRC_FILES = ft_printf.c ft_printf_decimal.c get_flags.c ft_printf_str.c ft_printf_char.c\
	ft_convert.c ft_putlnbr.c ft_printf_float.c ft_printf_hexa.c ft_printf_octal.c ft_utils.c\

LIBFT_FILES = ft_putchar.c ft_putstr.c ft_tolower.c ft_isdigit.c ft_atoi.c ft_isalpha.c\
	ft_strdup.c ft_strlen.c ft_strnew.c ft_putnbr.c ft_memalloc.c ft_strcpy.c ft_bzero.c\
	ft_strncpy.c\

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))
LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_FILES))

OBJ = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/

$(NAME):
	@echo "Compilation en cours..."
	@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) générée avec succès"

.PHONY: all clean fclean re

all : $(NAME)

cp : 
	gcc main.c $(SRC) -L libft/ -lft $(INC)
run : 
	./a.out | cat -e

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all