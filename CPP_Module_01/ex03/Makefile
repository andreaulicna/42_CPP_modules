# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:40:54 by aulicna           #+#    #+#              #
#    Updated: 2024/01/18 20:17:38 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence

SRC = main.cpp \
	src/Weapon.class.cpp \
	src/HumanA.class.cpp \
	src/HumanB.class.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

CPP = c++

RM = rm -f

all: $(NAME)
	@echo "brain executable ready ✅"

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re