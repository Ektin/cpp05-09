# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 14:03:52 by EktinOpUrims      #+#    #+#              #
#    Updated: 2024/10/18 16:29:42 by EktinOpUrims     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#https://github.com/42Paris/42header

SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp \

HEADER = Bureaucrat.hpp \
	AForm.hpp \
	ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp \
	PresidentialPardonForm.hpp \
	Intern.hpp \

NAME = BUREAUCRAT

OBJDIR = .objects/

OBJ = $(SRC:%.cpp=$(addprefix $(OBJDIR), %.o))

CPP = c++

CPPFLAGS = -Wall -Wextra -Wpedantic -Werror
CPPFLAGS += -std=c++98

all:	$(NAME)

$(OBJDIR)%.o:	%.cpp $(HEADER)
	@mkdir -p $(OBJDIR)
	$(CPP) -o $@ -c $< $(CPPFLAGS)

$(NAME):	$(OBJ) $(HEADER)
	$(CPP) -o $(NAME) $(OBJ) $(CPPFLAGS) 

clean:
	@rm -rf $(OBJDIR)
	@rm -f $(wildcard .*.swp) $(wildcard .*.swo) $(wildcard .*.swx)

fclean:	clean	
	@rm -f $(NAME) $(wildcard *.out)

re:
	make fclean
	make	

.PHONY:
	clean fclean re
