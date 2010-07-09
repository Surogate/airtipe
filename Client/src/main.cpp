
#include <iostream>
#include  <cstring>

#include "Client.hpp"
#include "packets/PacketManager.h"

const int	width = 384;
const int	height = 256;
const int	bpp = 32;


int		main()
{
	Client client;
	PacketManager	pm;
	

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
	}
	while (42);
//	client.run();
}



/*
   int		main()
   {
   sf::RenderWindow	App;
   sf::Image		Image;


   App.Create(sf::VideoMode(width, height, bpp),
   "R-TYPE");

   if (!Image.LoadFromFile("../ressources/sprites/r-typesheet42.png"))
   return EXIT_FAILURE;
   sf::Sprite		Sprite(Image);

   Sprite.SetPosition(0, height / 2);

// Start game loop

while (App.IsOpened())
{
sf::Event Event;
std::string tape;


while (App.GetEvent(Event))
{
if ((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
{
App.Close();
return EXIT_SUCCESS;
}
}

float ElapsedTime = App.GetFrameTime();


if (App.GetInput().IsKeyDown(sf::Key:: Left))
Sprite.Move( -100 * ElapsedTime, 0);
if (App.GetInput().IsKeyDown(sf::Key::Right))
Sprite.Move( 100 * ElapsedTime, 0);
if (App.GetInput().IsKeyDown(sf::Key::Up))
Sprite.Move(0, -100 * ElapsedTime);
if (App.GetInput().IsKeyDown(sf::Key::Down))
Sprite.Move(0,  100 * ElapsedTime);

App.Clear();



App.Display();

}

return EXIT_SUCCESS;

}


*/
