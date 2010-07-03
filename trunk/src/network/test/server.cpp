#ifdef		UNIX
# include	"network/CTCPServer_Unix.h"
#endif

#include	<iostream>
#include	<cstdlib>

int		main()
{
	TCPServer	serv(22255, 8);

	if (serv.init())
	{
		std::cout << "server opened" << std::endl;
		serv.run();
		serv.close();
		std::cout << "server closed" << std::endl;
	}
	return (0);
}

