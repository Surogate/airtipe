/*
 * Graphics.cpp
 *
 *  Created on: Jul 3, 2010
 *      Author: Ayden
 */

#include <iostream>

#include "Graphics.hpp"

Graphics::Graphics()
{
  this->_width = 384;
  this->_height = 256;
  this->_bpp = 32;
  this->_name = "R-TYPE";
}

Graphics::~Graphics()
{}

void	Graphics::create_windows()
{
  this->_App.Create(sf::VideoMode(this->_width, this->_height, this->_bpp),
                    this->_name);
}

void	Graphics::close_windows()
{
  this->_App.Close();
}

void	Graphics::sprite_display(int x, int y)
{
  this->_Player.SetPosition(x, y);
}

void	Graphics::sprite_destroy()
{}

void	Graphics::load()
{
  if (!this->_Image.LoadFromFile("../ressources/sprites/r-typesheet42.png"))
    return ;
  this->_Player.SetImage(this->_Image);
  this->_Player.SetPosition(this->_width, this->_height);
}

void	Graphics::sprite_move()
{}

void	Graphics::sprite_anim()
{}


void	Graphics::getEvent(float ElapsedTime)
{
  sf::Event Event;
  std::string tape;
  while (this->_App.GetEvent(Event))
  {
    if ((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
    {
      this->_App.Close();
      return ;
    }
    if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::F1))
      this->sprite_display(0, this->_height / 2);
    if ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::F2))
      this->sprite_destroy();
  }

  if (this->_App.GetInput().IsKeyDown(sf::Key:: Left))
    this->_Player.Move( -100 * ElapsedTime, 0);
  if (this->_App.GetInput().IsKeyDown(sf::Key::Right))
    this->_Player.Move( 100 * ElapsedTime, 0);
  if (this->_App.GetInput().IsKeyDown(sf::Key::Up))
    this->_Player.Move(0, -100 * ElapsedTime);
  if (this->_App.GetInput().IsKeyDown(sf::Key::Down))
    this->_Player.Move(0,  100 * ElapsedTime);
}

void	Graphics::loop(NetWork& net)
{

  float ElapsedTime;
  while (this->_App.IsOpened())
  {
    this->_App.Clear();

    ElapsedTime = this->_App.GetFrameTime();
    this->getEvent(ElapsedTime);
    net.getEvent();
    this->draw();

    this->_App.Display();
  }
}

void	Graphics::draw()
{
  this->_App.Draw(this->_Player);
}

