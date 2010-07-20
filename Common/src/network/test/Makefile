NAME		=	server
CNAME		=	client

SRCS		=	main.cpp					\
				../CUDPServer_Unix.cpp		\
				../CUDPSession_Unix.cpp

CSRCS		=	client.cpp					\
				../CUDPClient_Unix.cpp		\
				../CUDPSession_Unix.cpp

OBJS		=	$(SRCS:.cpp=.o)
COBJS		=	$(CSRCS:.cpp=.o)

CXX			=	g++
CXXFLAGS	=	-W -Wall -I../../../include

RM			=	rm -rf

$(NAME)		:	$(OBJS)
			$(CXX) $(OBJS) -o $(NAME)

$(CNAME)	:	$(COBJS)
			$(CXX) $(COBJS) -o $(CNAME)

all			:	$(NAME) $(CNAME)

clean		:
			$(RM) $(OBJS)
			$(RM) $(COBJS)

fclean		: clean
			$(RM) $(NAME)
			$(RM) $(CNAME)

re			: fclean all

