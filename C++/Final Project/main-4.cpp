#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "ClassPlayer.h"
#include <stdlib.h>

using namespace sf;
using namespace std;

int RollDie() {
  srand((unsigned int)time(NULL));
  return rand() % 6 + 1;
}

int main() {
  RenderWindow window;
  window.create(VideoMode(1000,600),"Snakes and Ladders", Style::Resize);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  Texture boardText, gameDice, textLogo, bgText, intText;
  Texture playerOne, playerTwo, playerThree, playerFour;

  if(!intText.loadFromFile("intro.png"))
    return EXIT_FAILURE;
  if(!textLogo.loadFromFile("logooo.png"))
    return EXIT_FAILURE;
  if(!bgText.loadFromFile("bg.jpg"))
    return EXIT_FAILURE;
  if(!boardText.loadFromFile("bored.jpg"))
    return EXIT_FAILURE;
  if(!gameDice.loadFromFile("dice.png", IntRect(70, 0, 70, 71)))
     return EXIT_FAILURE;
  if(!playerOne.loadFromFile("p.png", IntRect(32, 0, 32, 32)))
     return EXIT_FAILURE;
  if(!playerTwo.loadFromFile("pp.png", IntRect(32, 0, 32, 32)))
     return EXIT_FAILURE;
  if(!playerThree.loadFromFile("ppp.png", IntRect(32, 0, 32, 32)))
     return EXIT_FAILURE;
  if(!playerFour.loadFromFile("pppp.png", IntRect(32, 0, 32, 32)))
     return EXIT_FAILURE;

  Sprite intro(intText);
  Sprite bgImg(bgText);
  Sprite gameLogo(textLogo);
  Sprite board(boardText);
  Sprite die(gameDice);
  bgImg.setPosition(0, 0);
  gameLogo.setPosition(630, 50);
  board.setPosition(20,5);
  die.setPosition(751, 380);

  //player sprites
  Sprite plyr1(playerOne);
  Sprite plyr2(playerTwo);
  Sprite plyr3(playerThree);
  Sprite plyr4(playerFour);

  //player positions
  plyr1.setPosition(740,300);
  plyr2.setPosition(780,300);
  plyr3.setPosition(820,300);
  plyr4.setPosition(860,300);

	PlyInfo aPlyr, bPlyr, cPlyr, dPlyr, *plyrPtr = new PlyInfo;
	Sprite *movePlyr = new Sprite, a = plyr1, b = plyr2, c = plyr3, d = plyr4;
	aPlyr.status = bPlyr.status = aPlyr.pMove = true;
	bool contGame = true, flagRoll = false, flagPlyr = true, chkTile, change = false, flagNext = false, open = true;
	int n;

	Font font;
	if(!font.loadFromFile("handsean.ttf"))
    return EXIT_FAILURE;

	Text roll("Rolling dice", font, 20), ap("Player 1", font, 10), bp("Player 2", font, 10), cp("Player 3", font, 10), dp("Player 4", font, 10);
	roll.setPosition(755, 451);
	ap.setPosition(740,225);

  while(window.isOpen()) {
    cout<<"OPEN"<<endl;
		if(plyrPtr->checkWinner())
			contGame = false;

    Event event;
    while(window.pollEvent(event) && contGame) {
      if(event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
        window.close();

      if(Keyboard::isKeyPressed(Keyboard::Space) && !flagRoll && !change) {
          n = 10;
          flagRoll = true;
          cout<<"ROLL DICE: "<<n<<endl;
          sleep(seconds(1));
      }

      if(!change && n == 0) {
        chkTile = checkTile(plyrPtr);
        cout<<"CHECK TILE "<<plyrPtr->tile<<": "<<chkTile<<endl;
        sleep(seconds(1));
        flagNext = true;
      }

      if(flagRoll) {

        if(!chkTile) {
          if(plyrPtr->tile / 10 < 10 && plyrPtr->tile % 10 == 0 && plyrPtr->tile / 10 > 0 && n > 1) {
            movePlyr->move(0, -55);
            cout<<"MOVE UP "<<plyrPtr->tile / 10<<" < 10"<<endl;
            //sleep(seconds(1));
          }else
          if(plyrPtr->tile % 20 < 20 && plyrPtr->tile % 20 > 10 && n > 1) {
           movePlyr->move(-55, 0);
           cout<<" MOVE LEFT "<<plyrPtr->tile % 20<<" < 20"<<endl;
           //sleep(seconds(1));
          }else
          if(plyrPtr->tile % 10 < 10 && n > 1) {
            movePlyr->move(55, 0);
            cout<<"MOVE RIGHT "<<plyrPtr->tile % 10<<" < 10"<<endl;
            //sleep(seconds(1));
          }

          if(n > 0) {
            n--;
            plyrPtr->tile++;
            cout<<"DICE TILE UPDATE"<<" dice: "<<n<<" tile: "<<plyrPtr->tile<<endl;
            sleep(seconds(1));
          }

          if(n == 0 && flagNext) {
            flagRoll = false;
            flagPlyr = true;
            cout<<"NEXT PLAYER"<<endl;
            sleep(seconds(1));
            flagNext = false;
          }else {
            cout<<"MOVE PLAYER"<<" dice: "<<n<<" tile: "<<plyrPtr->tile<<endl;
            //sleep(seconds(1));
          }
        }else {
          change = true;
          flagRoll = false;
        }
    }

    if(change) {
      movePlyr->setPosition(plyrPtr->x, plyrPtr->y);
      change = false;
      flagPlyr = true;
    }

    if(flagPlyr) {
      if(aPlyr.pMove) {
        aPlyr.pMove = false;
        movePlyr = &a;
        plyr1.setPosition(740,305);
        plyr2.setPosition(780,300);
        plyrPtr = &aPlyr;
        cout<<"PLAYER 1 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }else {
        aPlyr.pMove = true;
        movePlyr = &b;
        plyr1.setPosition(740,300);
        plyr2.setPosition(780,305);
        plyrPtr = &bPlyr;
        cout<<"PLAYER 2 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }
      if(!plyrPtr->tile)
        movePlyr->setPosition(40, 545);
      flagPlyr = false;
		}

    window.draw(bgImg);
    sleep(seconds(2));
    window.draw(gameLogo);
    window.draw(board);
    //window.draw(die);
    window.draw(plyr1);
    window.draw(plyr2);
    window.draw(plyr3);
    window.draw(plyr4);

    if(aPlyr.status)
      window.draw(a);
    if(bPlyr.status)
      window.draw(b);
    if(cPlyr.status)
      window.draw(c);
    if(dPlyr.status)
      window.draw(d);
    window.draw(*movePlyr);
    if(aPlyr.pMove)
      window.draw(ap);
    //window.draw(roll);

    window.display();
		window.clear();

    }
  }

  return EXIT_SUCCESS;
}
