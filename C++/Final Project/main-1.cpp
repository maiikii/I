#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;
using namespace std;

//all current logic in game menu
//make structures for:

///menu
void MainMenu() {
//how many players will play

}

///snakes and ladders displayBoard
void GameBoard() {
//updates player's current position
//background should be put here?

}

///gameDice
int RollDie() {
  srand((unsigned int)time(NULL));
  return rand()%6+1;
}

///player move (?)
void ChangePosition (int dice){
///switch(dice):
///case 1: if 1 == 1 move (x,y coordinates?)
//takes the position of each player
//moves the players
}

///checkSnakesOrLadders
void CheckTilePosition () {
//check if position of player hits a tile with snake or ladder
//then do necessary moves

}

///check winner
void CheckWinner () {
//if reach tile 100 or position (1,1)
//if winner == 0, switch to next player
}

///switch players
int Player () {
//if player == a, player = b etc
}

int main() {
  RenderWindow window;
  //no resizing of game window, no fullscreen mode
  window.create(VideoMode(1000,710),"Snakes and Ladders", Style::Close);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  //need to convert background into sprite first
  //idk why that's what the dude said
  Texture BgTexture, gameDice;
  //player icons!
  Texture playerOne, playerTwo;
  Texture playerThree, playerFour;

  //background image
  if(!BgTexture.loadFromFile("board.png"))
    return EXIT_FAILURE;
  //dice image
  if(!gameDice.loadFromFile("dice.png", IntRect(70, 0, 70, 71)))
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
  players.setPosition(800,210);
  playerss.setPosition(840,210);
  playersss.setPosition(880,210);

  int flagLogo = 1;
  Texture textL, textP;
  if(!textL.loadFromFile("logo.png"))
    return EXIT_FAILURE;
  //if(!textP.loadFromFile("play.png"))
    //return EXIT_FAILURE;
  Sprite logo(textL);//, play(textP);
  logo.setPosition(Vector2f(240.5, 181.5));
  //logo.setPosition(Vector2f())

  int x = 0, fl = 1;
  Sprite p1, p2, p3, p4, pmove;

  p1=player;
  p1.setPosition(32, )

  //game loop
  while(window.isOpen()) {
    window.clear();
    window.draw(backgroundImage);
    window.draw(die);
    window.draw(player);
    window.draw(players);
    window.draw(playerss);
    window.draw(playersss);
    window.draw(p1);
    window.display();

    if(!x) {
      fl = 0;
      x = RollDie();
    }

    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();
      else {
        cout<<x<<endl;
        switch(event.type) {

        }
      }
    }
  }
  return EXIT_SUCCESS;
}
