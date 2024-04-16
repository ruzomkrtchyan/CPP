NAME			= yey
SRCS			= main.cpp
OBJS			= $(patsubst %.cpp, %.o, $(SRCS))
CC				= c++ 
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -std=c++98
MK				= mkdir -p

all:			 $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


%.o:	%.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re