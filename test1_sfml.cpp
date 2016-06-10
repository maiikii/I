#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
   // create the window
   sf::RenderWindow window(sf::VideoMode(800, 500), "My window");
   sf::Font font;
   sf::Text text;

   // run the program as long as the window is open
   while (window.isOpen()) {

     // check all the window's events that were triggered since the last iteration of the loop
     sf::Event event;

     while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
     }

     // clear the window with black color
     window.clear(sf::Color::Black);
     if(!font.loadFromFile("arial.ttf"))
        // error...

     text.setFont(font);
     text.setString("SHINee");
     text.setCharacterSize(24);
     text.setColor(sf::Color::Red);
     text.setStyle(sf::Text::Bold | sf::Text::Underlined);


     // draw everything here...
     // window.draw(...);

     // end the current frame
     window.draw(text);
     window.display();
  }

  return 0;
}
