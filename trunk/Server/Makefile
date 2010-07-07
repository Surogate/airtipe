STAG		= $(shell uname -s)
STAG		!= uname -s
MTAG		= $(shell uname -m)
MTAG		!= uname -m

TAG		= $(MTAG)-$(STAG)

############### PROJECT

NAME		= R-type_server


############### DIRECTORIES

DIR_SRC			= ./src/
DIR_SRC_COMMON	= ../src/
DIR_INC			= ./inc/
DIR_INC_COMMON	= ../include/
DIR_LIB			= ./lib/
DIR_BIN			= ./bin/

############### FILES

SRC		= \
		$(DIR_SRC)main.cpp								\
		$(DIR_SRC)Server.cpp							\
		$(DIR_SRC_COMMON)network/CTCPServer_Unix.cpp	\
		$(DIR_SRC_COMMON)network/CTCPSession_Unix.cpp

INC		= \

SRC_LIB		= \

OBJ			= $(SRC:.cpp=.o)

############### FLAGS ###############
#########  DEFINES

DEFINE_i386-Darwin	= -D UNIX

DEFINE_i386-FreeBSD	= -D UNIX

DEFINE_i686-Linux	= -D UNIX

DEFINE			= $(DEFINE_$(TAG))


#########  INCLUDES

IFLAGS_i386-Darwin	= \

IFLAGS_i386-FreeBSD	= \

IFLAGS_i686-Linux	= \

IFLAGS				= \
			$(IFLAGS_$(TAG)) 	\
			-I$(DIR_INC) -I$(DIR_INC_COMMON)

#########  LIBRARIES

LFLAGS_i386-Darwin	= \
			

LFLAGS_i386-FreeBSD	= \
			

LFLAGS_i686-Linux	= \
			

LFLAGS				= \
					$(LFLAGS_$(TAG))	\
					-L$(DIR_LIB)		\

#########  COMPILE FLAGS

CFLAGS			+= -O3 -W -Wall -ansi -pedantic $(DEFINE) $(IFLAGS)

############### BINARIES ###############

CC_FreeBSD	= g++
CC_Linux	= g++
CC_Darwin	= g++ -arch i386
CC			= $(CC_$(STAG))

RM			= rm -f
CD			= cd
ETAGS		= etags
CP			= cp
ECHO_FreeBSD= echo -e
ECHO_SunOS	= echo -e
ECHO_Linux	= echo -e
ECHO_Darwin	= echo
ECHO		= $(ECHO_$(STAG))

############### COLOR ###############

END		= \033[m
RED		= \033[31m
GREEN	= \033[32m
ORANGE	= \033[33m
BLUE	= \033[34m
PINK	= \033[35m
CYAN	= \033[36m
GREY	= \033[37m

############### COMMANDS ###############

all		: $(NAME)

$(NAME)	: $(OBJ)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME)$(END)"
	$(CC) -o$(DIR_BIN)$(NAME) $(OBJ) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

tar		:
	@$(ECHO) "$(CYAN)[TAR]$(END)"
	tar -cf $(NAME).tar.gz		\
		Makefile		\
		$(INC)		\
		$(SRC)
	@$(ECHO) "$(CYAN)[TAR] - DONE$(END)"

############### SUFFIXIES

.SUFIXIES	: .cpp .o .m
.cpp.o		:
	@$(ECHO) "$(ORANGE)[OBJ]$(GREY)"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(ECHO) "$(ORANGE)[OBJ] -DONE$(END)"


############### CLEAN OPTION

clean		:
	@$(ECHO) "$(RED)[CLEAN]"
	$(RM) $(OBJ)
	@$(ECHO) "$(GREEN)[CLEAN] -DONE$(END)"

fclean		: clean
	@$(ECHO) "$(RED)[FCLEAN]"
	$(RM) $(DIR_BIN)$(NAME)
	@$(ECHO) "$(GREEN)[FCLEAN] -DONE$(END)"

cleanall	: fclean
	@$(ECHO) "$(RED)[CLEANALL]"
	$(RM) $(DIR_SRC)*~
	$(RM) $(DIR_INC)*~
	$(RM) *~
	@$(ECHO) "$(GREEN)[CLEANALL] -DONE$(END)"


###############OTHERS OPTION ###############

re		: fclean all

.PHONY		: $(NAME) all .c.o library clean fclean re cleanall

#EOF
