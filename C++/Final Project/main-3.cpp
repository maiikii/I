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
  //no resizing of game window, no fullscreen mode
  window.create(VideoMode(1000,600),"Snakes and Ladders", Style::Resize);
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
  if(!BgTexture.loadFromFile("bored.jpg"))
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
	Sprite *movePlyr = new Sprite, a = plyr1, b = plyr2, c = plyr3, d = plyr4;
	aPlyr.status = bPlyr.status = aPlyr.pMove = true;
	bool contGame = true, flag = false;
	int x = 0;

	Font font;
	if(!font.loadFromFile("handsean.ttf"))
    return EXIT_FAILURE;

	Text roll;
	roll.setPosition(755, 451);

  while(window.isOpen()) {
    cout<<"OPEN"<<endl;
		if(plyrPtr->checkWinner())
			contGame = false;

    Event event;
    while(window.pollEvent(event) && contGame) {
      if(event.type == Event::Closed || ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
        window.close();

      if(Keyboard::isKeyPressed(Keyboard::Space) && !flag) {
          x = RollDie();
          flag = true;
          cout<<"ROLL DICE: "<<x<<endl;
          sleep(seconds(1));
      }

      if(flag && Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left)) {
        if(Keyboard::isKeyPressed(Keyboard::Up)) {
          if(plyrPtr->tile / 10 < 10 && plyrPtr->tile / 10 > 0 && x > 1) {
            movePlyr->move(0, -40);
            cout<<"MOVE UP "<<plyrPtr->tile / 10<<endl;
            sleep(seconds(1));
          }
        }

        if(Keyboard::isKeyPressed(Keyboard::Right) && x > 1) {
          if(plyrPtr->tile % 10 < 10) {
            movePlyr->move(50, 0);
            cout<<"MOVE RIGHT "<<plyrPtr->tile % 10<<endl;
            sleep(seconds(1));
          }
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) && x > 1) {
          if(plyrPtr->tile % 20 < 20) {
           movePlyr->move(-50, 0);
           cout<<" MOVE LEFT "<<plyrPtr->tile % 20<<endl;
           sleep(seconds(1));
          }
        }
        if(x > 0) {
          x--;
          plyrPtr->tile++;
        }
        if(!x) {
          flag = false;
          cout<<"NEXT PLAYER, PRESS SPACE"<<endl;
          sleep(seconds(1));
        }
        cout<<"MOVE PLAYER"<<" "<<x<<" "<<plyrPtr->tile<<endl;
        sleep(seconds(2));
    }

    if(flag) {
      if(aPlyr.pMove) {
        aPlyr.pMove = false;
        movePlyr = &a;
        plyr1.setPosition(755, 215);
        plyr2.setPosition(800,210);
        plyrPtr = &aPlyr;
        if(!aPlyr.tile)
          a.setPosition(30, 540);
        cout<<"PLAYER 1 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }else {
        aPlyr.pMove = true;
        movePlyr = &b;
        plyr1.setPosition(755, 210);
        plyr2.setPosition(800,215);
        plyrPtr = &bPlyr;
        if(!bPlyr.tile)
          b.setPosition(50, 540);
        cout<<"PLAYER 2 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }
      flag = false;
		}


    window.draw(backgroundImage);
    window.draw(die);
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
    window.draw(roll);
    window.display();
		window.clear();

    }
  }

  return EXIT_SUCCESS;
}
