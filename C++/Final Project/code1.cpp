#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
using namespace std;

bool playerMove(int* x) {
  if(*x) {
    *x--;
    return true;
  }
  return false;
}

int RollDie() {
  srand((unsigned int)time(NULL));
  return rand()%6+1;
}

int main() {
  RenderWindow window(VideoMode(1000, 550), "Snakes and Ladders");
  window.setPosition(Vector2i(100,0));

  Texture bg, p1, p2;
  if(!bg.loadFromFile("board.jpg"))
    return EXIT_FAILURE;
  if(!p1.loadFromFile("p1.png"))
    return EXIT_FAILURE;
  if(!p2.loadFromFile("p2.png"))
    return EXIT_FAILURE;

  Sprite board(bg), p(p1), pp(p2);
  board.setPosition(100, 25);
  p.setPosition(120, 450);
  int x = 0, fl, pmove = 0;

  while(window.isOpen()) {
    window.clear();
    window.draw(board);
    window.draw(p);
    window.display();

    if(!x) {
      x = RollDie();
      fl = 1;
    }

    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();
      else {
        cout<<x<<endl;
        /*if(event.type == Event::KeyPressed && x != 0) {
          switch(event.key.code) {
            case Keyboard::Up: p.move(0,-130);
            break;
            case Keyboard::Down: p.move(0,130);
            break;
            case Keyboard::Left: p.move(-136,0);
            break;
            case Keyboard::Right: p.move(136,0);
            break;
          }
          x--;
        }*/
        if(event.type == Event::KeyPressed && (event.key.code==Keyboard::Space) && fl == 1) {
          p.move(136,0);
          fl = 2;
          x--;
          pmove++;
        }else if(fl == 2) {
          p.move(136,0);
          x--;
          pmove++;
        }
      }
    }
  }

  return EXIT_SUCCESS;
}
