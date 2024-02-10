# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 11:40:54 by aulicna           #+#    #+#              #
#    Updated: 2024/02/10 15:12:27 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Integer

SRC = main.cpp \
	Integer.class.cpp

HEADER = Integer.class.hpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

CPP = c++

RM = rm -f

all: $(NAME)
	@echo "Integer executable ready ✅"

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) -o $@ $^

$(OBJ): $(HEADER)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re