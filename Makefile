# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 17:12:18 by tlebrize          #+#    #+#              #
#    Updated: 2015/02/12 19:09:11 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

SRC_NAME = ft_get_next_line.c \
		   ft_libstr_0.c \
		   ft_libstr_1.c \
		   ft_core.c


SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./include/

INC = $(addprefix -I, $(INC_PATH))

NAME = ft_sh1

CC = gcc

CFLAGS = -Wall -Wextra -Werror



all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ) -g

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	$(CC) $(CFLAGS) $(INC) -o $@ -c $< -g

clean :
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean : clean
	rm -fv $(NAME)

re : fclean all

norme :
	norminette $(SRC)
	norminette $(INC_PATH)*.h