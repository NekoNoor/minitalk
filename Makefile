# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nschat <nschat@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/17 17:19:37 by nschat        #+#    #+#                  #
#    Updated: 2021/06/29 17:26:37 by nschat        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc

IDIR = include
CFLAGS = -Wall -Wextra -Werror -I $(IDIR)

SRC_CLIENT = src_client/main.c
SRC_SERVER = src_server/main.c
SRC_SHARED = src_shared/helpers.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_SHARED = $(SRC_SHARED:.c=.o)

NAME = client
NAME_SERVER = server

vpath %.c src_client src_server

.PHONY: clean fclean

all: $(NAME) $(NAME_SERVER)

$(NAME): $(IDIR)/helpers.h | $(OBJ_CLIENT) $(OBJ_SHARED)
	$(CC) $(CFLAGS) $| -o $@

$(NAME_SERVER): $(IDIR)/helpers.h | $(OBJ_SERVER) $(OBJ_SHARED)
	$(CC) $(CFLAGS) $| -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_SHARED)

fclean: clean
	$(RM) $(NAME) $(NAME_SERVER)

re: fclean all
