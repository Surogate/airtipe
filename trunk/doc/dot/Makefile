SRCS		=	Server/Server.dot			\
				Server/ThreadMutex.dot		\
				Server/Network.dot			\
				Server/Packet.dot			\
				Server/Ressources.dot		\
				Server/Activity_Party.dot	\
				Common/Factory.dot

DOT			=	dot

doc			:	clean
				$(DOT) $(SRCS) -T png -O
				mv -f Server/*.png .;
				mv -f Common/*.png .;

clean		:
				rm -f *.png
