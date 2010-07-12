CLIENT	= ./Client
SERVER	= ./Server
BIN	= ./bin

all	: client server

client	:
	@(cd $(CLIENT) && $(MAKE))
	cp $(CLIENT)/bin/* $(BIN)

server	:
	@(cd $(SERVER) && $(MAKE))
	cp $(SERVER)/bin/* $(BIN)

clean:
	@(cd ./Client && $(MAKE) $@)
	@(cd ./Server && $(MAKE) $@)

fclean:
	@(cd ./Client && $(MAKE) $@)
	@(cd ./Server && $(MAKE) $@)

