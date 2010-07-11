#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>


const int	width = 800;
const int	height = 600;

#include <iostream>
#include "SpriteManager.hpp"

int main()
{
  std::cout << "Allo le monde" << std::endl;
  sf::RenderWindow	Game;
  Game.Create(sf::VideoMode(width, height, 32), "R-TYPE");

  SpriteManager a;
  a.loadObjects("./../ressources/sprites/spritepng");


  sf::Image im;
  im.LoadFromFile("./../ressources/sprites/spritepng/r-typesheet5.png");
  sf::Sprite test(im);
  test.SetPosition(0, 0);

  //AGameObject *go = a.getClone(0, 0);
  //sf::Sprite my = go->getSprite(0);
  //my.SetPosition(50,50);
  while (Game.IsOpened())
  {
    sf::Event Event;
    while (Game.GetEvent(Event))
    {
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
    Game.Draw(a.getClone(0, 0)->getSprite(0));
    Game.Draw(test);
    Game.Display();
  }
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
