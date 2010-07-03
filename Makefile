all	: client server

client	:
	@(cd ./Client && $(MAKE))

server	:
	@(cd ./Server && $(MAKE))

clean:
	@(cd ./Client && $(MAKE) $@)
	@(cd ./Server && $(MAKE) $@)