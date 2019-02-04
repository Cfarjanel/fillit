# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 16:32:57 by emoreau           #+#    #+#              #
#    Updated: 2018/02/28 18:25:18 by emoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit
SRC 	= ./srcs/main.c ./srcs/parser.c ./srcs/read.c ./srcs/parser2.c \
		./srcs/algo.c ./srcs/up_left.c ./srcs/map.c
FLAGS 	= -Werror -Wall -Wextra
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

%.o: %.c
		@$(CC) -c $< -o $@ $(FLAGS)

$(NAME): $(OBJ)
	@make -C ./libft
	@echo "$(GREEN)[✓]$(NC)$(CL) Objects of libft compiled$(NC)"
	@$(CC) $(FLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf fillit
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all
