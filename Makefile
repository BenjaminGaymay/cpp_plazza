NAME	= plazza

CC	= g++

RM	= rm -f

SRCS	= ./main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./inc/
CPPFLAGS += -W -Wall -Wextra

LDFLAGS += -pthread

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
