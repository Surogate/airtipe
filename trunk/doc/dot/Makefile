SRCS		=	Server/Server.dot			\
				Server/Network.dot			\
				Server/Packet.dot			\
				Server/Ressources.dot		\
				Common/ThreadMutex.dot		\
				Common/Factory.dot			\
				Common/SmartPointer.dot		\
				Common/Singleton.dot

DOT			=	dot

doc			:	clean
				$(DOT) $(SRCS) -T png -O
				mv -f Server/*.png .;
				mv -f Common/*.png .;

clean		:
				rm -f *.png
