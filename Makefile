# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plopes-c <plopes-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 16:32:02 by chales            #+#    #+#              #
#    Updated: 2023/03/17 20:26:31 by plopes-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tictactoe
NAME_U = tictactoe_ultimate

SRC = tictacoe.c
SRC_U = tictactoe_u2.0.c

LIBFT = libft/libft.a

OBJ = tictactoe.o
OBJ_U = tictactoe_u2.0.o

CFLAGS = -Wall -Wextra -Werror -fPIE

RM = rm -fr

all: $(NAME) $(NAME_U)

$(NAME):		$(OBJ)
				@make bonus -s -C libft
				@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_U):		$(OBJ_U)
				@make bonus -s -C libft
				@gcc $(CFLAGS) $(OBJ_U) $(LIBFT) -o $(NAME_U)

run:			$(NAME)
				@./$(NAME)

run_u:			$(NAME_U)
				@./$(NAME_U)

clean:		
				@$(RM) $(OBJ) $(OBJ_U)
				@make clean -s -C libft

fclean:			clean
				@$(RM) $(NAME) $(NAME_U)
				@make fclean -s -C libft

re:				fclean $(NAME) $(NAME_U)