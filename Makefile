# q
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/29 15:05:00 by ehugh-be          #+#    #+#              #
#    Updated: 2018/10/29 17:52:30 by ehugh-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = $(wildcard *.c) 
OBJ=$(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a
LIBDIR = libft/
HDR = fillit.h

all: $(SRC) $(NAME)

$(NAME): lib
	@$(CC) $(CFLAGS) -o $(NAME) main.c $(LIB) $(OBJ)

lib:  
	@make -C $(LIBDIR)

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@/bin/rm -f $(NAME) 
	@make -C $(LIBDIR) fclean

clean: cleanlib
	@/bin/rm -f $(OBJ)

cleanlib: 
	@make -C $(LIBDIR) clean

re: fclean all

