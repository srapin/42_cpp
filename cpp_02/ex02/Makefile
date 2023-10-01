# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 22:14:25 by srapin            #+#    #+#              #
#    Updated: 2023/10/01 01:18:06 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -std=c++98 -Wall -Wextra -Werror -g3

NAME = fixed
CC = c++
SRCS = \
	main.cpp\
	Fixed.cpp\

OBJS = $(SRCS:.cpp=.o)
	
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean $(NAME)