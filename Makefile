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
OBJ_FOLDER = obj/

SRC_FILES = ft_printf.c ft_printf_decimal.c get_flags.c ft_printf_str.c ft_printf_char.c \
	ft_convert.c ft_putlnbr.c ft_printf_float.c ft_printf_hexa.c ft_printf_octal.c ft_deal_flags.c \
	get_alpha_flags.c ft_printf_dec_str.c \

LIBFT_FILES = ft_putchar.c ft_putstr.c ft_tolower.c ft_isdigit.c ft_atoi.c ft_isalpha.c\
	ft_strdup.c ft_strlen.c ft_strnew.c ft_putnbr.c ft_memalloc.c ft_strcpy.c ft_bzero.c \
	ft_strncpy.c ft_strsub.c ft_putwstr.c ft_wcharlen.c ft_putwchar.c ft_wstrcpy.c \
	ft_wstrdup.c ft_wstrlen.c ft_wstrncpy.c ft_wstrnew.c ft_isupper.c ft_islower.c \
	ft_strrev.c \

OBJ_SRC_NAME = $(SRC_FILES:.c=.o)
OBJ_LIBFT_NAME = $(LIBFT_FILES:.c=.o)

SRC = $(addprefix $(SRC_FOLDER), $(SRC_FILES))
LIBFT = $(addprefix $(LIBFT_FOLDER), $(LIBFT_FILES))

OBJ_SRC = $(addprefix $(OBJ_FOLDER), $(OBJ_SRC_NAME))
OBJ_LIBFT = $(addprefix $(OBJ_FOLDER), $(OBJ_LIBFT_NAME))


FLAGS = -Wall -Wextra -Werror
INC = -Iincludes/

.PHONY: all clean fclean re


$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.c
	@mkdir $(OBJ_FOLDER) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(OBJ_FOLDER)%.o: $(LIBFT_FOLDER)%.c
	@mkdir $(OBJ_FOLDER) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(NAME): $(OBJ_SRC) $(OBJ_LIBFT)
	@echo "Compilation en cours..."
	@ar rc $(NAME) $(OBJ_SRC) $(OBJ_LIBFT)
	@ranlib $(NAME)
	@echo "$(NAME) générée avec succès!"

all : $(NAME)

clean :
	@rm -rf $(OBJ_SRC) $(OBJ_LIBFT)
	@rmdir $(OBJ_FOLDER) 2> /dev/null || true

fclean : clean
	@rm -rf $(NAME)

re : fclean all