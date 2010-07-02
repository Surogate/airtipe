##
## Makefile for example in /u/all/bertra_b/cu/workspace/c/corewar/src
## 
#

SNAME		=	server
SSRCS		=	server.cpp							\
				../CTCPServer_Unix.cpp				\
				../CTCPSession_Unix.cpp				\
				../../thread/CAbsMutex_Unix.cpp		\
				../../thread/CAbsThread_Unix.cpp

SOBJS		=	$(SSRCS:.cpp=.o)
CXX			=	g++
CXXFLAGS	=	-I../../../include -Wextra -Wall -D UNIX
LDFLAGS		=	-lpthread
RM			=	rm -f

$(SNAME)		:	$(SOBJS)
				$(CXX) $(LDFLAGS) $(SOBJS) -o $(SNAME)

all			:	$(SNAME)

clean		:
				$(RM) $(SOBJS)

fclean		:	clean
				$(RM) $(SNAME)

re			:	fclean all

