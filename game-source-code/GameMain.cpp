#include <iostream>
#include <SFML/Graphics.hpp>
#include "Maze.h"

using namespace std;

int main(){

sf::RenderWindow window(sf::VideoMode(900,700), "Super PacMan");

auto maze = Maze{};
maze.getMazeFromFile();  // this must go
auto currMaze = maze.getLogicMaze();  // this returns the Logic maze vector;


while (window.isOpen())
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    switch(event.type)
    {
    case sf::Event::Closed:
        window.close();
        break;
    }
  }


  ///update- movements,rotations, etc here.

  ///Draw everything-the first takes the background
 for(auto wall : currMaze)
 {
     if(wall.Orientation=='v')
        {
          sf::RectangleShape rect(sf::Vector2f(10.f,wall.length));
          rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
          window.draw(rect);

        }
     else if(wall.Orientation=='h')
     {
        sf::RectangleShape rect(sf::Vector2f(wall.length,10.f));
        rect.setPosition(sf::Vector2f(wall.x_coord,wall.y_coord));
        window.draw(rect);

     }

 }


  /// display
  window.display();
}




return 0;
}
