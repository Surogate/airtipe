NAME		=	udp

SRCS		=	main.cpp					\
				../CUDP_Unix.cpp			\
				../CUDPSession_Unix.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX			=	g++
CXXFLAGS	=	-W -Wall -I../../../include

RM			=	rm -rf

$(NAME)		:	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
			$(RM) $(OBJS)

fclean		: clean
			$(RM) $(NAME)

re			: fclean all

