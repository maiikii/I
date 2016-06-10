#include<SFML/Graphics.hpp>
#include<iostream>
#include "ClassPlayer.h"

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
  RenderWindow window;
  window.create(VideoMode(1000,700),"Snakes and Ladders", Style::Resize);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  Texture BgTexture, gameDice;
  Texture playerOne, playerTwo;
  Texture playerThree, playerFour;

  //background image
  if(!BgTexture.loadFromFile("board.png"))
    return EXIT_FAILURE;
  //dice image
  if(!gameDice.loadFromFile("dice.png"))
     return EXIT_FAILURE;
  //player image
  if(!playerOne.loadFromFile("player1.png", IntRect(32, 0, 32, 48)))
     return EXIT_FAILURE;
  if(!playerTwo.loadFromFile("player2.png", IntRect(32, 0, 32, 48)))
     return EXIT_FAILURE;
  if(!playerThree.loadFromFile("player3.png", IntRect(32, 0, 32, 48)))
     return EXIT_FAILURE;
  if(!playerFour.loadFromFile("player4.png", IntRect(32, 0, 32, 48)))
     return EXIT_FAILURE;
  Sprite backgroundImage(BgTexture);
  Sprite die(gameDice);
  backgroundImage.setPosition(20,5);
  die.setPosition(751, 45);
  //player sprites
  Sprite player(playerOne);
  Sprite players(playerTwo);
  Sprite playerss(playerThree);
  Sprite playersss(playerFour);
  //player positions
  player.setPosition(755,210);
  players.setPosition(795,210);
  playerss.setPosition(835,210);
  playersss.setPosition(875,210);

  Sprite pmove = player;
  PlyInfo a, b, *ptr;
  a.status = b.status = true;
  a.pMove = true;

  while(window.isOpen()) {

    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();

      if(Keyboard::isKeyPressed(Keyboard::Right) && fl == 1)

    }
  return EXIT_SUCCESS;
}
