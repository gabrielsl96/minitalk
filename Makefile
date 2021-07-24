NAME_S=server
NAME_C=client

FLAGS = -Wall -Werror -Wextra
CC = gcc

DIR_S = ./dir_server
DIR_C = ./dir_client

SRC_S= $(DIR_S)/main.c $(DIR_S)/ft_putnmb.c
SRC_C= $(DIR_C)/main.c $(DIR_C)/ft_atoi.c $(DIR_S)/ft_putnmb.c

OBJS_S = $(SRC_S:.c=.o)
OBJS_C = $(SRC_C:.c=.o)

all: 		$(NAME_S) $(NAME_C)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME_S):	$(OBJS_S)
			$(CC) $(FLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_C):	$(OBJS_C)
			$(CC) $(FLAGS) $(OBJS_C) -o $(NAME_C)

clean:
			rm -rf $(OBJS_S)
			rm -rf $(OBJS_C)

fclean: 	clean
			rm -rf $(NAME_S)
			rm -rf $(NAME_C)

re: fclean all

.PHONY: clean fclean all re
