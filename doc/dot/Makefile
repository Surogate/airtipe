SRCS		=	Server/Server.dot			\
				Server/ThreadMutex.dot		\
				Server/Network.dot			\
				Server/Packet.dot			\
				Server/Ressources.dot

DOT			=	dot

doc			:	clean
				$(DOT) $(SRCS) -T png -O
				mv Server/*.png .

clean		:
				rm -f *.png
