
NAME = RPN

SRCS = main.cpp \
		RPN.cpp \

OBJS = $(SRCS:%.cpp=%.o)

RM = rm -f

FLAGS = -Wall -Werror -Wextra -std=c++98 -g3

$(NAME) : $(OBJS)
		c++ $(OBJS) $(FLAGS) -o $(NAME)

all: $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all 