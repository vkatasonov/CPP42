# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 22:45:59 by vkatason          #+#    #+#              #
#    Updated: 2024/08/12 14:10:06 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serena
USER := $(shell whoami)
CC = c++ 
#INC = includes
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
#-I$(INC) -g -fsanitize=leak
CLEAN = rm -Rf
SRC = 	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \

OBJS := $(SRC:.cpp=.o)

#######COLORS#######

BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RST		:= \033[0m

all: $(NAME)

%.o:%.cpp
	@$(CC) -c $(CPPFLAGS) $< -o $@
	@echo "$(GREEN)The object file $@ was successfully compiled. $(RST)"

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)The app $(NAME) was successfully compiled. $(RST)"

clean:
	@$(CLEAN) $(OBJS)
	@echo "$(RED)Removing:$(RST) all objects files of $(NAME) app."

fclean: clean
	@$(CLEAN) $(NAME)
	@echo "$(RED)Removing:$(RST) $(NAME) app."
	@echo "$(RED)Cleaned up!$(RST)"

re: clean fclean all

.PHONY : all fclean re