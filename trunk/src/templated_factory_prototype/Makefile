NAME		=	Factory
SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX			=	g++

RM			=	rm -f

$(.cpp=.o)	:
				$(CXX) -c $(SRCS) -o $(OBJS)

all			:	$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
