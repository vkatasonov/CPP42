# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 10:10:00 by vkatason          #+#    #+#              #
#    Updated: 2024/07/11 14:43:04 by vkatason         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
USER := $(shell whoami)
CC = c++ 
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
#-fsanitize=leak
CLEAN = rm -Rf
SRC = 	megaphone.cpp
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
DEFAULT	:= \033[0m

all: $(NAME)

%.o:%.cpp
	@$(CC) -c $(CPPFLAGS) ${SRC}
	@echo "$(GREEN)The object files were successfully compiled. $(DEFAULT)"

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)
	@echo "$(GREEN)The app $(NAME) was successfully compiled. $(DEFAULT)"

clean:
	@$(CLEAN) $(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(NAME)."

fclean: clean
	@$(CLEAN) $(NAME)
	@echo "$(RED)Removing:$(DEFAULT) $(NAME) Program."
	@echo "$(RED)Cleaned up!$(DEFAULT)"

re: clean fclean all

.PHONY : all fclean re