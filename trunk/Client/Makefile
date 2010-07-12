STAG		= $(shell uname -s)
STAG		!= uname -s
MTAG		= $(shell uname -m)
MTAG		!= uname -m

TAG		= $(MTAG)-$(STAG)

############### PROJECT

NAME		= R-type




DIR_COMMON	= ../Common
DIR		= .

D_SRC		= $(DIR)/src
D_SRC_COMMON	= $(DIR_COMMON)/src

D_INC		= $(DIR)/inc
D_INC_COMMON	= $(DIR_COMMON)/include

D_LIB		= $(DIR)/lib

D_BIN		= $(DIR)/bin

############### FILES

SRC		= \
		$(D_SRC)/main.cpp				\
		$(D_SRC)/Client.cpp				\
		$(D_SRC)/Graphics.cpp				\
		$(D_SRC)/EventManager.cpp			\
		$(D_SRC)/Network.cpp				\
		$(D_SRC)/Ressources.cpp				\
		$(D_SRC)/TCPClient.cpp				\
		$(D_SRC)/NetWork.cpp				\
		$(D_SRC)/AGameObject.cpp			\
		$(D_SRC)/AGameWindows.cpp			\
		$(D_SRC)/SpriteManager.cpp			\
		$(D_SRC)/EventManager.cpp			\
		$(D_SRC_COMMON)/packets/PacketManager.cpp	\
		$(D_SRC_COMMON)/packets/Packet.cpp		\
		$(D_SRC_COMMON)/packets/PacketHeader.cpp

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

IFLAGS			= \
			$(IFLAGS_$(TAG)) 	\
			-I$(D_INC_COMMON)	\
			-I$(D_INC)

#########  LIBRARIES

LFLAGS_i386-Darwin	= \

LFLAGS_i386-FreeBSD	= \

LFLAGS_i686-Linux	= \

LFLAGS			= \
			$(LFLAGS_$(TAG))	\
			-L$(D_LIB)		\
			-lsfml-graphics		\
			-lGLU			\
			-lGL			\
			-lsfml-window		\
			-lsfml-network		\
			-lsfml-system

#########  COMPILE FLAGS

CFLAGS			+= -O3 -W -Wall $(DEFINE) $(IFLAGS)

############### BINARIES ###############

CC_FreeBSD	= g++
CC_Linux	= g++
CC_Darwin	= g++ -arch i386
CC		= $(CC_$(STAG))

RM		= rm -f
CD		= cd
ETAGS		= etags
CP		= cp
ECHO_FreeBSD	= echo -e
ECHO_Linux	= echo -e
ECHO_Darwin	= echo
ECHO		= $(ECHO_$(STAG))

############### COLOR ###############

END	= \033[m
RED	= \033[31m
GREEN	= \033[32m
ORANGE	= \033[33m
BLUE	= \033[34m
PINK	= \033[35m
CYAN	= \033[36m
GREY	= \033[37m

############### COMMANDS ###############

all		: $(NAME)

$(NAME)		: $(OBJ)
	@$(ECHO) "$(CYAN)[LINKING]: $(NAME)$(END)"
	$(CC) -o$(D_BIN)/$(NAME) $(OBJ) $(LFLAGS)
	@$(ECHO) "$(GREEN)[LINKING] - DONE$(END)"

tar		:
	@$(ECHO) "$(CYAN)[TAR]$(END)"
	tar -cf $(NAME).tar.gz		\
	Makefile			\
	$(INC)				\
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
	$(RM) $(D_BIN)/$(NAME)
	@$(ECHO) "$(GREEN)[FCLEAN] -DONE$(END)"

cleanall	: fclean
	@$(ECHO) "$(RED)[CLEANALL]"
	$(RM) $(D_SRC)*~
	$(RM) $(D_INC)*~
	$(RM) *~
	@$(ECHO) "$(GREEN)[CLEANALL] -DONE$(END)"


###############OTHERS OPTION ###############

re		: fclean all

.PHONY	: $(NAME) all .c.o library clean fclean re cleanall

#EOF
