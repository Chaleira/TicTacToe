# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chales <chales@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 16:32:02 by chales            #+#    #+#              #
#    Updated: 2023/03/09 16:48:16 by chales           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tictactoe

SRC = tictacoe.c

LIBFT = libft/libft.a

OBJ = tictactoe.o

CFLAGS = -Wall -Wextra -Werror

RM = rm -fr

all: $(NAME)

$(NAME):		$(OBJ)
				@make bonus -s -C libft
				@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

run:			$(NAME)
				@./$(NAME)
			
clean:		
				@$(RM) $(OBJ)
				@make clean -s -C libft

fclean:			clean
				@$(RM) $(NAME)
				@make fclean -s -C libft

re:				fclean $(NAME)