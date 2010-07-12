#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>


const int	width = 800;
const int	height = 600;

#include <iostream>
#include <QtGui/QApplication>
#include <QtGui/QPushButton>

#include "SpriteManager.hpp"
#include "MainWindow.hpp"

int main(int ac, char **av)
{
	QApplication app(ac, av);

	//Client *b = new Client();
	MainWindow qtwindow(NULL);
	qtwindow.show();

	sf::RenderWindow	Game;
	Game.Create(sf::VideoMode(width, height, 32), "R-TYPE");
	SpriteManager a;
	a.loadObjects("./ressources/sprites/");

	AGameObject *go = a.getClone(0, 0);
	if (go == NULL)
	{
		std::cout << "Bad pointer" << std::endl;
		exit(1);
	}

	sf::Clock cl;
	cl.Reset();
	while (Game.IsOpened())
	{
		sf::Event Event;
		while (Game.GetEvent(Event))
		{
			std::cout << "3" << std::endl;
			if ((Event.Type == sf::Event::KeyPressed))
			{
				//tape = Event.Text.Unicode;
				//std::cout << tape << std::endl;
			}
			if ((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
			{
				Game.Close();
				return EXIT_SUCCESS;
			}
		}
		Game.Clear();
		if (cl.GetElapsedTime() > 0.2f)
		{
			cl.Reset();
			go->goNextFrame();
		}
		go->draw(Game);
		Game.Display();
	}
	return app.exec();
}

/*
#include <iostream>
#include  <cstring>

#include "Client.hpp"
//#include "packets/PacketManager.h"

const int	width = 384;
const int	height = 256;
const int	bpp = 32;


int		main()
{
	Client client;

	 * PacketManager	pm;
	

	client.Net.c.connect(std::string("localhost"), 22255);
	Packet* packet = pm.CreatePacket(Login);
	DataLogin* data = new (packet->datas) DataLogin;
	data->id = 9;
	memcpy(data->login, "azeazeazeazeae", 15);
	data->login[14] = 0;
	if (!client.Net.c.failed())
	{
		packet->header->dataSize = sizeof(*data);
		client.Net.c.send(packet->header, sizeof(*packet->header));
		client.Net.c.send(data, sizeof(*data));
		client.Net.c.send(packet->header, sizeof(*packet->header));
		client.Net.c.send(data, sizeof(*data));
		client.Net.c.send(packet->header, sizeof(*packet->header));
		client.Net.c.send(data, sizeof(*data));
		client.Net.c.send(packet->header, sizeof(*packet->header));
		client.Net.c.send(data, sizeof(*data));
	}
	while (42);
	client.run();
}
*/
