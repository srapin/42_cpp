# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:55:22 by srapin            #+#    #+#              #
#    Updated: 2024/03/15 23:23:51 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = base

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 

FILES = \
		Base \
		main
		


INCLUDES_FILES = \
		Base \
		A \
		B \
		C \



SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .cpp, $(FILES)))

OBJS_DIR = obj
OBJS = ${patsubst ${SRCS_DIR}/%.cpp, ${OBJS_DIR}/%.o, ${SRCS}}


INCLUDES_DIR = inc
INCLUDES = $(addprefix $(INCLUDES_DIR)/, $(addsuffix .hpp, $(INCLUDES_FILES)))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $@

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.cpp $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -o $@ -c $<



clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all


.PHONY: all clean fclean re 
