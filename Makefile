# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/17 17:19:37 by nschat        #+#    #+#                  #
#    Updated: 2021/06/18 11:42:39 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_CLIENT = src_client/main.c
SRC_SERVER = src_server/main.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server
NAME = $(NAME_CLIENT) $(NAME_SERVER)

vpath %.c src_client src_server

.PHONY: clean fclean

all: $(NAME)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
