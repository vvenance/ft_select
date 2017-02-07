# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvenance <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/11 14:25:59 by vvenance          #+#    #+#              #
#*   Updated: 2016/11/14 18:51:50 by mtassett         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC_PATH = ./src/
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
 ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
 ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcchr.c\
 ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
 ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
 ft_strjoin.c ft_strtrim.c ft_strtrim2.c ft_strsplit.c ft_itoa.c ft_putchar.c\
 ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c\
 ft_putnbr.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
 ft_lstiter.c ft_lstmap.c ft_lstgetn.c ft_lst_push_back.c ft_strrev.c\
 ft_lstlen.c ft_create_dlist.c ft_create_node.c ft_dlst_push_back.c\
 ft_itoa_base.c ft_putaddr.c ft_cat.c ft_isspace.c ft_strjoin_free.c\
 ft_without_space_len.c ft_strupcase.c ft_strnrev.c ft_sqrt.c ft_swap.c\
 ft_strlowcase.c ft_strcapitalize.c ft_str_is_uppercase.c ft_str_is_printable.c\
 ft_str_is_numeric.c ft_str_is_lowercase.c ft_str_is_alhpa.c ft_nbword.c\
 ft_recursive_power.c ft_recursive_factorial.c ft_is_prime.c ft_is_negative.c\
 ft_find_next_prime.c ft_power.c ft_lstaddend.c ft_floorl.c ft_wstrlen.c ft_free.c\
 get_next_line.c


OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAGS =  -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[36mLIBFT:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) -I./inc -o $@ -c $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[\033[36m------------------------------------------\033[0m]"
	@echo "[\033[36m---------------- LIBFT - OK --------------\033[0m]"
	@echo "[\033[36m------------------------------------------\033[0m]"

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "[\033[31mSuppression des .o\033[0m]"

fclean: clean
	@rm -fv $(NAME)
	@echo "[\033[31mSuppression des .o\033[0m]"
	@echo "[\033[31mSuppression de \033[36m$(NAME)\033[0m\033[0m]"

re: fclean all

.PHONY: all clean fclean re
