##
## Makefile for example in /u/all/bertra_b/cu/workspace/c/corewar/src
## 
#

NAME		=	threads
SRCS		=	main.cpp					\
				../CAbsThread_Unix.cpp		\
				../CAbsMutex_Unix.cpp

OBJS		=	$(SRCS:.cpp=.o)
CXX			=	g++
CXXFLAGS	=	-I../../../include -Wextra -Wall -D UNIX
LDFLAGS		=	-lpthread
RM			=	rm -f

$(NAME)		:	$(OBJS)
				$(CXX) $(LDFLAGS) $(OBJS) -o $(NAME)

all			:	$(NAME)

clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

