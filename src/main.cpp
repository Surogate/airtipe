#include <SFML/Graphics.hpp>
#include <iostream>

const int	width = 384;
const int	height = 256;


int		main()
{
  sf::RenderWindow	App;
  sf::Image		Image;


  App.Create(sf::VideoMode(width, height, 32),
             "R-TYPE");

  if (!Image.LoadFromFile("../img/r-typesheet42.gif"))
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
      if ((Event.Type == sf::Event::KeyPressed))
      {
        tape = Event.Text.Unicode;
        std::cout << tape << std::endl;
      }
      if ((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Key::Escape)))
      {
        App.Close();
        return EXIT_SUCCESS;
      }
    }
    float ElapsedTime = App.GetFrameTime();

    if (App.GetInput().IsKeyDown(sf::Key::Left))
      Sprite.Move(-100 * ElapsedTime, 0);
    if (App.GetInput().IsKeyDown(sf::Key::Right))
      Sprite.Move( 100 * ElapsedTime, 0);
    if (App.GetInput().IsKeyDown(sf::Key::Up))
      Sprite.Move(0, -100 * ElapsedTime);
    if (App.GetInput().IsKeyDown(sf::Key::Down))
      Sprite.Move(0,  100 * ElapsedTime);

    App.Clear();

    App.Draw(Sprite);

    App.Display();

  }

  return EXIT_SUCCESS;

}
