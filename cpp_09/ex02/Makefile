# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srapin <srapin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 22:14:25 by srapin            #+#    #+#              #
#    Updated: 2024/04/04 17:47:32 by srapin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
	
CC			= c++
FLAGS		= -Wall -Wextra -g3 -std=c++98# -Werror  
RM			= rm -rf

OBJDIR = obj

FILES		= main \
				PmergeMe\

HEADER_FILE	= PmergeMe \

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HDR			= $(HEADER_FILE:=.hpp)

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g
endif

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(CC) $(OBJ) $(OPTS) -o $(NAME)
	@printf "$(_SUCCESS) $(GREEN)- ready.\n$(RESET)"

$(OBJDIR)/%.o: %.cpp $(HDR)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	

fclean: clean
	@$(RM) $(NAME)

re: fclean all