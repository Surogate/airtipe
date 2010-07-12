/*
 * Graphics.cpp
 *
 *  Created on: Jul 3, 2010
 *      Author: Ayden
 */

#include <SFML/Graphics.hpp>

#include "Graphics.hpp"
#include "Client.hpp"
#include "Network.hpp"
#include "EventManager.hpp"

Graphics::Graphics(Client *c)
{
  this->_rwindow = new sf::RenderWindow();
  this->_client = c;
  this->_width = 384;
  this->_height = 256;
  this->_bpp = 32;
  this->_name = "R-type";

}

Graphics::~Graphics()
{}

void	Graphics::create_windows(bool fullScreen)
{
  this->_rwindow->Create(sf::VideoMode(this->_width, this->_height, this->_bpp),
                                      this->_name);
}

void	Graphics::close_windows()
{
  this->_rwindow->Close();
}

void	Graphics::loop()
{
  float ElapsedTime;
  while (this->_rwindow->IsOpened())
  {
    this->_rwindow->Clear();
    ElapsedTime = this->_rwindow->GetFrameTime();
    this->_client->getEventM().getEvent(ElapsedTime);
    this->_client->getNetwork().getEvent();
    this->draw();
    this->_rwindow->Display();
  }
}

void	Graphics::draw()
{
  //this->_client->getRessources().Draw(this->_Player);
}

void	Graphics::sprite_display(int x, int y)
{
  //this->_Player.SetPosition(x, y);
}

void	Graphics::sprite_destroy()
{}

void	Graphics::load()
{
  /*
  if (!this->_Image.LoadFromFile("../../ressources/sprites/r-typesheet42.png"))
    return ;
  this->_Player.SetImage(this->_Image);
  this->_Player.SetPosition(this->_width, this->_height);
  */
}

void	Graphics::sprite_move()
{

}

sf::RenderWindow & Graphics::getWindow()
{
	return *_rwindow;
}

void	Graphics::sprite_anim()
{

}
