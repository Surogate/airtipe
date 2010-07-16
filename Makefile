EXE_SERVER	= R-Type_server
EXE_CLIENT	= R-Type

CLIENT	= ./Client
SERVER	= ./Server
BIN	= ./bin

QMAKE	= qmake-qt4

all	: client server

client	:
	@(cd $(CLIENT) && $(QMAKE) && $(MAKE))
	@(cp -v $(CLIENT)/bin/$(EXE_CLIENT) $(BIN))

server	:
	@(cd $(SERVER) && $(MAKE))
	@(cp -v $(SERVER)/bin/$(EXE_SERVER) $(BIN))

clean:
	@(cd ./Client && $(MAKE) $@)
	@(cd ./Server && $(MAKE) $@)

fclean:
	@(cd ./Client && $(MAKE) $@)
	@(cd ./Server && $(MAKE) $@)

