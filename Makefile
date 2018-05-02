NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp			\
	  ./srcs/Plazza.cpp		\
	  ./srcs/ProcessManager.cpp	\
	  ./srcs/Parser/Parser.cpp	\
	  ./srcs/Log/Log.cpp		\
	  ./srcs/CommandManager.cpp	\
	  ./srcs/Fifo.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./includes/		\
	   -I ./includes/Macro		\
	   -I ./includes/Parser		\
	   -I ./includes/Log

CPPFLAGS += -W -Wall -Wextra

LDFLAGS += -pthread

COM_COLOR	= \033[0;34m
OBJ_COLOR	= \033[0;36m
OK_COLOR	= \033[0;32m
ERROR_COLOR	= \033[0;31m
WARN_COLOR	= \033[0;33m
DEL_COLOR	= \033[0;31m
NO_COLOR	= \033[m

OK_STRING	= "[OK]"
ERROR_STRING	= "[ERROR]"
WARN_STRING	= "[WARNING]"
COM_STRING	= "[Compiling]"
BUILD_STRING	= "[Building]"
DEL_STRING	= "[Deleting]"
FORMAT_STRING	= "%-55b%b"

all: $(NAME)

%.o:	%.cpp
	@printf "%-58b" "$(COM_COLOR)$(COM_STRING)  $(OBJ_COLOR)$(<)$(NO_COLOR)";
	@$(CC) $(CPPFLAGS) -c $< -o $@; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%b" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else \
		printf "%b" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;


$(NAME): $(OBJS)
	 @echo
	 @$(CC) $(OBJS) -o $(NAME) $(LDFLAGS); \
	 RESULT=$$?; \
	 if [ $$RESULT -ne 0 ]; then \
 		printf $(FORMAT_STRING) "$(COM_COLOR)$(BUILD_STRING)   $(OBJ_COLOR)$(@)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	 else \
		printf $(FORMAT_STRING) "$(COM_COLOR)$(BUILD_STRING)   $(OBJ_COLOR)$(@)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	 fi;

clean:
	@$(RM) $(OBJS)
	@printf "$(DEL_COLOR)$(DEL_STRING)$(NO_COLOR)   %s\n" $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@printf "%b" "$(DEL_COLOR)$(DEL_STRING)   $(NO_COLOR)$(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
