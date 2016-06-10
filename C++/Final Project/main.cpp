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
int RollDie (int dice) {
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
  window.create(VideoMode(1000,600),"Snakes and Ladders", Style::Resize);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  //need to convert background into sprite first
  //idk why that's what the dude said
  Texture BgTexture, gameDice, bgText;
  //player icons!
  Texture playerOne, playerTwo;
  Texture playerThree, playerFour;

  //background image
  if(!BgTexture.loadFromFile("bored.jpg"))
    return EXIT_FAILURE;
  if(!bgText.loadFromFile("bg.jpg"))
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
  Sprite backgroundImage(BgTexture), bgImg(bgText);
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

  //game loop
  while(window.isOpen()) {
    window.clear();
    window.draw(bgImg);
    window.draw(backgroundImage);
    window.draw(die);
    window.draw(player);
    window.draw(players);
    window.draw(playerss);
    window.draw(playersss);
    window.display();

    Event event;
    //do while loop?
    while(window.pollEvent(event)) {
    /// if(Event.type == sf::Event::Closed)
    ///   Window.close();
    //while CheckWinner = 0;
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();
      else {
        switch(event.type) {
          //will be temporarily using this to determine the x,y position
          case Event::MouseMoved:
            cout<<"X: "<< event.mouseMove.x << " Y: " << event.mouseMove.y <<endl;
            break;
          //using this as reference to determine where menu button should be placed, etc
          case Event::MouseButtonPressed:
            if(event.mouseButton.button == Mouse::Left)
                cout<<"Mouse clicked!"<<endl;
            break;
        }
      }
    }
  }
  return EXIT_SUCCESS;
}
