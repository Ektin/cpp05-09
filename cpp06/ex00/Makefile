# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 19:45:44 by EktinOpUrims      #+#    #+#              #
#    Updated: 2025/01/05 15:05:57 by EktinOpUrims     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp \
	ScalarConverter.cpp \
	utils.cpp \

HEADER = ScalarConverter.hpp \
	utils.hpp \

OBJDIR = .objects/

OBJ = $(SRC:%.cpp=$(addprefix $(OBJDIR), %.o))

CPP = g++

CPPFLAGS = -Wall -Wextra -Wpedantic -Werror

CPPFLAGS += -std=c++98

NAME = convert

all: $(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CPP) -o $(NAME) $(OBJ) $(CPPFLAGS)

$(OBJDIR)%.o:	%.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CPP)	-c -o $@ $< $(CPPFLAGS)

clean:
	rm -rf $(OBJDIR)
	rm -f $(wildcard *.o)

fclean:	clean
	rm -rf $(NAME) $(wildcard *.out)
	rm -rf $(wildcard .*.swp) $(wildcard .*.swx) $(wildcard .*.swo)
	rm -f $(wildcard *.o) $(wildcard *.a)

re:
	make fclean
	make

.PHONY:
	clean fclean re
