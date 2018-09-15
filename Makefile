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

SRC_FOLDER = src
LIBFT_FOLDER = libft
OBJ_FOLDER = obj

SRC_FILES = ft_printf.c ft_printf_decimal.c get_flags.c ft_printf_str.c ft_printf_char.c \
	ft_convert.c ft_putlnbr.c ft_printf_float.c ft_printf_hexa.c ft_printf_octal.c ft_deal_flags.c \
	get_alpha_flags.c ft_printf_dec_str.c \

LIBFT_FILES = ft_putchar.c ft_putstr.c ft_tolower.c ft_isdigit.c ft_atoi.c ft_isalpha.c\
	ft_strdup.c ft_strlen.c ft_strnew.c ft_putnbr.c ft_memalloc.c ft_strcpy.c ft_bzero.c \
	ft_strncpy.c ft_strsub.c ft_putwstr.c ft_wcharlen.c ft_putwchar.c ft_wstrcpy.c \
	ft_wstrdup.c ft_wstrlen.c ft_wstrncpy.c ft_wstrnew.c ft_isupper.c ft_islower.c \
	ft_strrev.c \


SRC = $(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ = $(addprefix $(OBJ_FOLDER)/,$(OBJ_NAME))
LIBFT = $(addprefix $(LIBFT_FOLDER)/, $(LIBFT_FILES))

OBJ_NAME = $(SRC_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/

$(NAME):
	@echo "Compilation en cours..."
	@$(CC) -c $(FLAGS) $(SRC) $(LIBFT) $(INC)
	@ar rc $(NAME) $(OBJ_NAME)
	@ranlib $(NAME)
	@echo "$(NAME) générée avec succès!"

.PHONY: all clean fclean re

all : $(NAME)

cp : 
	$(CC) main.c $(SRC) -L libft/ -lft $(INC)
run : 
	@./a.out | cat -e

clean :
	@rm -rf $(OBJ_NAME)

fclean : clean
	@rm -rf $(NAME)

re : fclean all