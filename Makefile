EXE_SERVER	= R-type_server
EXE_CLIENT	= R-type

CLIENT	= ./Client
SERVER	= ./Server
BIN	= ./bin

all	: client server

client	:
	@(cd $(CLIENT) && $(MAKE))
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

