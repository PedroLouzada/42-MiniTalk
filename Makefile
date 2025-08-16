# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 20:52:10 by pbongiov          #+#    #+#              #
#    Updated: 2025/08/16 19:02:01 by pbongiov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

SERVER_FILES = server.c
CLIENT_FILES = client.c

SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR = objs

SERVER_OBJS	=$(addprefix $(OBJS_DIR)/, $(SERVER_FILES:.c=.o))
CLIENT_OBJS =$(addprefix $(OBJS_DIR)/, $(CLIENT_FILES:.c=.o))

CFLAGS = -g -Wall -Wextra -Werror
CC = cc

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJS)
	@$(CC) $(CFLAGS)  $(SERVER_OBJS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS)  $(CLIENT_OBJS) -o $(NAME_CLIENT)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
	rm -rf $(NAME_SERVER) $(NAME_CLIENT)

re:		fclean 	all

s:
	make re && clear && ./server

c:
	make re && clear && ./client

.PHONY : all clean fclean re