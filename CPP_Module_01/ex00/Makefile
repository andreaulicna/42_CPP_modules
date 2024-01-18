# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:40:54 by aulicna           #+#    #+#              #
#    Updated: 2024/01/13 12:10:50 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC = src/main.cpp \
	src/Zombie.class.cpp \
	src/newZombie.cpp \
	src/randomChump.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

CPP = c++

RM = rm -f

all: $(NAME)
	@echo "zombie executable ready ✅"

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re