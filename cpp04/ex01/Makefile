

# ---------------- Nickname --------------
NAME			=	BRAIN
SANITIZED_NAME	=	BRAIN_sanitized
RM				=	rm -f
CC				=	g++ #c++ ou g++ , clang pas à l'ecole
FLAGS			=	-Wall -Wextra -Werror -std=c++98
BS_TXT			=	echo "\n"
SANITIZE_FLAGS	=	-fsanitize=address -g

# ---------------- Objets ---------------
OBJ				= 	${SRC:.cpp=.o}
SANITIZED_OBJ	= 	${SRC:.cpp=.san.o}

%.o: 				%.cpp
					@$(CC) $(FLAGS) -c $< -o $@
%.san.o: %.cpp
	@$(CC) $(FLAGS) $(SANITIZE_FLAGS) -c $< -o $@

# ---------------- Sources -----------
SRC 			=	main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

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
				@echo "$(GREEN) ✨------Brain ex01------✨ $(ENDCOLOR)"
sanitize: clean $(SANITIZED_NAME)

$(SANITIZED_NAME): $(SANITIZED_OBJ)
	@$(CC) $(FLAGS) $(SANITIZE_FLAGS) -o $(SANITIZED_NAME) $(SANITIZED_OBJ)
	@echo "$(GREEN) ✨------Brain sanitize ex01------✨ $(ENDCOLOR)"

# --------------- Tests  --------------------


# --------------- Service nettoyage --------------------
clean:
				@${RM} ${OBJ} $(SANITIZED_OBJ) 
				@${RM} -r *.dSYM


fclean:			clean
				@${RM} ${NAME} $(SANITIZED_NAME)
				@echo "$(GREEN)Cleaning success 🌸$(ENDCOLOR)"

re:				fclean all clean
				@echo "$(LILAC)Deep Cleaning 🧹$(ENDCOLOR)"

.PHONY : all clean fclean re 