# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 19:04:13 by srapin            #+#    #+#              #
#    Updated: 2023/10/04 22:32:14 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = phoneBook

CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g3 

FILES = \
		Bureaucrat \
		Form \
		main \



INCLUDES_FILES = \
		Bureaucrat \
		Form \


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