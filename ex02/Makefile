# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: yitoh <yitoh@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2024/05/24 10:54:52 by yitoh         #+#    #+#                  #
#    Updated: 2024/08/12 17:11:18 by yitoh         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=signForm
CC		=c++
CFLAGS	=-Wall -Werror -Wextra -std=c++11 -g #-fsanitize=leak
RM		=rm -f
SRC		=Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
		 RobotomyRequestForm.cpp PresidntialPardon.cpp main.cpp
OBJ		=$(SRC:%.cpp=obj/%.o)

all:	$(NAME)

$(OBJ):		$(SRC)
				@mkdir -p $(dir $@)
				@printf "\e[1;34mBuilding $@\n\e[0;00m"
				@$(CC) $(CFLAGS) -c $(@:obj/%.o=%.cpp) -o $@

$(NAME):	$(OBJ)
				@printf "\e[1;36mCompiling $@\n\e[0;00m"
				@$(CC) $(CFLAGS) $^ -o $@
				@printf "\e[1;32mDone\e[0;00m\n"

clean:
				@$(RM) -r obj
				@printf "\e[1;35mCleaned Object Files\n\e[0;00m"

fclean:		clean
				@$(RM) $(NAME)
				@printf "\e[1;31mCleaned Executables\n\e[0;00m"

re:			fclean all

.PHONY:		all clean fclean re