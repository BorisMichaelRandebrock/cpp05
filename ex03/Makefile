# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandebr <brandebr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 13:03:51 by brandebr          #+#    #+#              #
#    Updated: 2024/11/12 16:23:22 by brandebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =  At_least_this_beats_coffee-making

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp PlanetaryRelocationForm.cpp 

SRC_P = src/

OBJ_DIR = obj/

INC_DIR = inc/

HEADERS = $(addprefix $(INC_DIR), Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp Intern.hpp PlanetaryRelocationForm.hpp)

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -g #-fsanitize=address

INCLUDES = -I$(INC_DIR)

all: Makefile $(NAME)

$(OBJ_DIR)%.o: $(SRC_P)%.cpp $(HEADERS) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

valgrind: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

totvalgrind: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -f $(NAME)
	/bin/rm -f *_shrubbery 
	
re: fclean all

.PHONY: all clean fclean re
