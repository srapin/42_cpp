# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:23:33 by srapin            #+#    #+#              #
#    Updated: 2023/09/29 18:52:33 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAGS = -std=c++98 -Wall -Wextra -Werror -g3

NAME = megaphone
CC = c++
SRCS = ./megaphone.cpp

OBJS = $(SRCS:.cpp=.o)
	
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)