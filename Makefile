NAME		= ft_select

CC			= GCC

CFLAGS		= -Wall -Werror -Wextra

SRC_PATH	= ./src/

SRC_NAME	= $(SRC_PATH)main.c

OBJ_PATH	= ./obj/

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

I_LIBFT 	= -Ilibft

LIBFT 		= -Llibft $(I_LIBFT) -lft

all:	$(NAME)


$(NAME): $(SRCS_O)
			@make -C libft
			@$(CC) $(CC_FLAGS) -o $(NAME) $(SRC_NAME) $^ -I . $(LIBFT)
			@echo "$(NAME) has been successfuly done :)"

%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) -I$ . -o $@ -c $< $(I_LIBFT)

re: fclean all


clean:
		@make clean -C libft
		@rm -f $(SRCS_O)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C libft

.PHONY: all clean fclean re 