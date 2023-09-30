# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/29 18:55:22 by srapin            #+#    #+#              #
#    Updated: 2023/09/30 23:25:58 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = attak

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 

FILES = \
		HumanA\
		HumanB\
		Weapon\
		main


INCLUDES_FILES = \
		HumanA\
		HumanB\
		Weapon\


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