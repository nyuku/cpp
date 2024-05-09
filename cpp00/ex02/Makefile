# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angela <angela@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 11:38:21 by angela            #+#    #+#              #
#    Updated: 2024/05/09 22:52:03 by angela           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------- Nickname --------------
NAME			=	account
RM				=	rm -f
CC				=	clang++ #c++ ou g++
FLAGS			=	-Wall -Wextra -Werror -std=c++98
BS_TXT			=	echo "\n"

# ---------------- Objets ---------------
OBJ				= 	${SRC:.cpp=.o}
%.o: 				%.cpp
					@$(CC) $(FLAGS) -c $< -o $@

# ---------------- Sources -----------
SRC 			=	tests.cpp Account.cpp

# ---------------- Color --------------

RED				= \033[0;31m
BRIGHT_RED		= \033[1;31m
LIGHT_RED       = \033[0;91m
YELLOW			= \033[0;33m
PEACH           = \033[0;93m
LIGHT_YELLOW	= \033[1;33m
GREEN			= \033[0;32m
SOFT_GREEN      = \033[0;92m
LIGHT_GREEN		= \033[1;32m

LIGHTPURPLE		= \033[1;35m
LIGHT_LILAC		= \033[1;34m
LIGHT_MAGENTA   = \033[0;95m
LIGHT_CYAN		= \033[1;36m
MAGENTA			= \033[0;35m
LILAC			= \033[0;94m
BLUE			= \033[0;34m
CYAN			= \033[0;36m

WHITE			= \033[1;37m
BLACK			= \033[0;30m
DARKGRAY		= \033[1;30m
LIGHT_GRAY      = \033[0;37m

ENDCOLOR		= \033[0m
BOLD			= \033[1m
END_BOLD		= \033[0m

# --------------- Regles --------------------
all:			$(NAME)

$(NAME):		$(OBJ)
				@$(CC) $(FLAGS) $(OBJ) -o $@
				@echo "$(GREEN) Find the lost file  $(ENDCOLOR)"

# --------------- Tests  --------------------


# --------------- Service nettoyage --------------------
clean:
				@${RM} ${OBJ}

fclean:			clean
				@${RM} ${NAME}
				@echo "$(GREEN)Cleaning success 🌸$(ENDCOLOR)"

re:				fclean all clean
				@echo "$(LILAC)Deep Cleaning 🧹$(ENDCOLOR)"

.PHONY : all clean fclean re 