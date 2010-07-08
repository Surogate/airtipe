NAME		=	Factory
SRCS		=	main.cpp		\
				hexdump.cpp
OBJS		=	$(SRCS:.cpp=.o)

RM			=	rm -f

INCDIR		=	-I ../../../include/

CXX			=	g++ 

$(OBJS)		:
				$(CXX) -c $(SRCS) $(INCDIR) -std=c++0x

all			:	$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
