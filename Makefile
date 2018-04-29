NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp	\
	  ./srcs/Plazza.cpp

NB_FILE = `find . -name "*.cpp" | wc -l`

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./includes/
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

all: $(NAME)

%.o:	%.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-50b%b" "$(COM_COLOR)$(COM_STRING)  $(OBJ_COLOR)$(<)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	else \
		printf "%-50b%b" "$(COM_COLOR)$(COM_STRING)  $(OBJ_COLOR)$(<)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi;


$(NAME): $(OBJS)
	 @echo
	 @$(CC) $(OBJS) -o $(NAME) $(LDFLAGS); \
	 RESULT=$$?; \
	 if [ $$RESULT -ne 0 ]; then \
 		printf "%-50b%b" "$(COM_COLOR)$(BUILD_STRING)   $(OBJ_COLOR)$(@)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
	 else \
		printf "%-50b%b" "$(COM_COLOR)$(BUILD_STRING)   $(OBJ_COLOR)$(@)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	 fi;

clean:
	@$(RM) $(OBJS)
	@printf "$(DEL_COLOR)$(DEL_STRING)$(NO_COLOR)   %s\n" $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@printf "%b" "$(DEL_COLOR)$(DEL_STRING)   $(NO_COLOR)$(NAME)\n"

re: fclean all

.PHONY: all clean fclean re