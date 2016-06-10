#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "ClassPlayer.h"

using namespace sf;
using namespace std;

int main() {
  RenderWindow window;
  //no resizing of game window, no fullscreen mode
  window.create(VideoMode(1000,710),"Snakes and Ladders", Style::Resize);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  //need to convert background into sprite first
  //idk why that's what the dude said
  Texture BgTexture, gameDice, textLogo;
  Texture playerOne, playerTwo, playerThree, playerFour;

  //game logo
  if(!textLogo.loadFromFile("logo.png"))
    return EXIT_FAILURE;
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

  Sprite gameLogo(textLogo);
  Sprite backgroundImage(BgTexture);
  Sprite die(gameDice);
  gameLogo.setScale(Vector2f(150, 100));
  gameLogo.setPosition(750, 25);
  backgroundImage.setPosition(20,5);
  die.setPosition(751, 380);

  //player sprites
  Sprite plyr1(playerOne);
  Sprite plyr2(playerTwo);
  Sprite plyr3(playerThree);
  Sprite plyr4(playerFour);

  //player positions
  plyr1.setPosition(755,210);
  plyr2.setPosition(800,210);
  plyr3.setPosition(840,210);
  plyr4.setPosition(880,210);

	PlyInfo aPlyr, bPlyr, cPlyr, dPlyr, *plyrPtr = new PlyInfo;
	Sprite *movePlyr = new Sprite;
	aPlyr.pMove = true;
	bool contGame = true;
	int x = RollDie(), fl;

	Font font;
	if(!font.loadFromFile("handsean.ttf"))
    return EXIT_FAILURE;

	Text roll("Rolling Dice", font, 15);
	roll.setPosition(755, 451);

  movePlyr = &plyr1;
  plyrPtr = &aPlyr;
  movePlyr->setPosition(35, 630);

  while(window.isOpen()) {

		/*if(plyrPtr->checkWinner())
			contGame = false;

		int pos = plyrMove(&aPlyr, &bPlyr, &cPlyr, &dPlyr);
		if(aPlyr.pMove) {
      movePlyr = &plyr1;
      plyrPtr = &aPlyr;
		}
		if(bPlyr.pMove) {
      movePlyr = &plyr2;
      plyrPtr = &bPlyr;
		}
		if(cPlyr.pMove) {
      movePlyr = &plyr3;
      plyrPtr = &cPlyr;
		}
		if(dPlyr.pMove) {
      movePlyr = &plyr4;
      plyrPtr = &dPlyr;
		}*/

		plyrPtr->display();

		if(!x) {
      x = RollDie();
      fl = 1;
		}

		//if(!plyrPtr->tile)
      //movePlyr->setPosition(35, 630);

    Event event;
    while(window.pollEvent(event)) {
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();
      if(Keyboard::isKeyPressed(Keyboard::Right) && fl == 1) {
				movePlyr->move(70, 0);
				fl = 2;
				x--;
				plyrPtr->tile++;
			}else if(fl == 2) {
				movePlyr->move(136, 0);
				x--;
				plyrPtr->tile++;
			}

    }


    window.draw(backgroundImage);
    window.draw(die);
    window.draw(plyr1);
    window.draw(plyr2);
    window.draw(plyr3);
    window.draw(plyr4);
    window.draw(roll);
    window.draw(*movePlyr);
    window.display();
		window.clear();
  }
  return EXIT_SUCCESS;
}
