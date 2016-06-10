#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "ClassPlayer.h"
#include <stdlib.h>

using namespace sf;
using namespace std;

int main() {
  RenderWindow window;
  window.create(VideoMode(1000,710),"Snakes and Ladders", Style::Resize);
  window.setPosition(Vector2i(200,0));

  window.setKeyRepeatEnabled(false);
  Texture BgTexture, gameDice, textLogo;
  Texture playerOne, playerTwo, playerThree, playerFour;

  if(!textLogo.loadFromFile("logo.png"))
    return EXIT_FAILURE;
  if(!BgTexture.loadFromFile("board.png"))
    return EXIT_FAILURE;
  if(!gameDice.loadFromFile("dice.png", IntRect(70, 0, 70, 71)))
     return EXIT_FAILURE;
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
	bool contGame = true, flagRoll = false, flagPlyr = true;
	int n = 0, x, y;

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

      if(Keyboard::isKeyPressed(Keyboard::Space) && !flagRoll) {
          n = RollDie();
          flagRoll = true;
          cout<<"ROLL DICE: "<<n<<endl;
          sleep(seconds(1));
      }

      if(flagRoll) {
        if(plyrPtr->tile / 10 < 10 && plyrPtr->tile / 10 > 0) {
          movePlyr->move(0, -y);
          cout<<"MOVE UP "<<plyrPtr->tile / 10<<endl;
          sleep(seconds(1));
        }else
        if(plyrPtr->tile % 10 < 10) {
          movePlyr->move(x, 0);
          cout<<"MOVE RIGHT "<<plyrPtr->tile % 10<<endl;
          sleep(seconds(1));
        }else
        if(plyrPtr->tile % 20 < 20) {
         movePlyr->move(-x, 0);
         cout<<" MOVE LEFT "<<plyrPtr->tile % 20<<endl;
         sleep(seconds(1));
        }

        if(n > 0) {
          n--;
          plyrPtr->tile++;
        }

        if(!n) {
          flagRoll = false;
          flagPlyr = true;
          cout<<"NEXT PLAYER, PRESS SPACE"<<endl;
          sleep(seconds(1));
        }

        cout<<"MOVE PLAYER"<<" dice: "<<n<<" tile: "<<plyrPtr->tile<<endl;
        sleep(seconds(2));
    }

    if(flagPlyr) {
      if(aPlyr.pMove) {
        aPlyr.pMove = false;
        movePlyr = &a;
        plyr1.setPosition(755, 215);
        plyr2.setPosition(800,210);
        plyrPtr = &aPlyr;
        if(!aPlyr.tile)
          a.setPosition(30, 610);
        x = 70; y = 50;
        cout<<"PLAYER 1 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }else {
        aPlyr.pMove = true;
        movePlyr = &b;
        plyr1.setPosition(755, 210);
        plyr2.setPosition(800,215);
        plyrPtr = &bPlyr;
        if(!bPlyr.tile && flagRoll)
          b.setPosition(30, 610);
        x = 115; y = 50;
        cout<<"PLAYER 2 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }
      flagPlyr = false;
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

//

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
  Texture BgTexture, gameDice, textLogo;
  Texture playerOne, playerTwo, playerThree, playerFour;

  if(!textLogo.loadFromFile("logo.png"))
    return EXIT_FAILURE;
  if(!BgTexture.loadFromFile("bored.jpg"))
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
  plyr1.setPosition(740,210);
  plyr2.setPosition(780,210);
  plyr3.setPosition(820,210);
  plyr4.setPosition(860,210);

	PlyInfo aPlyr, bPlyr, cPlyr, dPlyr, *plyrPtr = new PlyInfo;
	Sprite *movePlyr = new Sprite, a = plyr1, b = plyr2, c = plyr3, d = plyr4;
	aPlyr.status = bPlyr.status = aPlyr.pMove = true;
	bool contGame = true, flagRoll = false, flagPlyr = true;
	int n = 0;

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

      if(Keyboard::isKeyPressed(Keyboard::Space) && !flagRoll) {
          n = 4;
          flagRoll = true;
          cout<<"ROLL DICE: "<<n<<endl;
          sleep(seconds(1));
      }

      if(flagRoll) {
        if(plyrPtr->tile / 10 < 10 && plyrPtr->tile / 10 > 0 && n > 1) {
          movePlyr->move(0, -40);
          cout<<"MOVE UP "<<plyrPtr->tile / 10<<" < 10"<<endl;
          sleep(seconds(1));
        }else
        if(plyrPtr->tile % 10 < 10 && n > 1) {
          movePlyr->move(60, 0);
          cout<<"MOVE RIGHT "<<plyrPtr->tile % 10<<" < 10"<<endl;
          sleep(seconds(1));
        }else
        if(plyrPtr->tile % 20 < 20 && n > 1) {
         movePlyr->move(-60, 0);
         cout<<" MOVE LEFT "<<plyrPtr->tile % 20<<" < 20"<<endl;
         sleep(seconds(1));
        }
        if(n > 0) {
          n--;
          plyrPtr->tile++;
          cout<<"DICE TILE UPDATE"<<endl;
          sleep(seconds(1));
        }

        if(n == 0) {
          flagRoll = false;
          flagPlyr = true;
          cout<<"NEXT PLAYER"<<endl;
          sleep(seconds(1));
        }else {
          cout<<"MOVE PLAYER"<<" dice: "<<n<<" tile: "<<plyrPtr->tile<<endl;
          sleep(seconds(1));
        }
    }

    if(flagPlyr) {
      if(aPlyr.pMove) {
        aPlyr.pMove = false;
        movePlyr = &a;
        plyr1.setPosition(740, 215);
        plyr2.setPosition(780,210);
        plyrPtr = &aPlyr;
        if(!aPlyr.tile)
          a.setPosition(30, 540);
        cout<<"PLAYER 1 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }else {
        aPlyr.pMove = true;
        movePlyr = &b;
        plyr1.setPosition(740, 210);
        plyr2.setPosition(780,215);
        plyrPtr = &bPlyr;
        if(!bPlyr.tile)
          b.setPosition(50, 540);
        cout<<"PLAYER 2 PRESS SPACE"<<endl;
        sleep(seconds(1));
      }
      flagPlyr = false;
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

    if(aPlyr.pMove)
      window.draw(ap);
    window.draw(roll);
    window.display();
		window.clear();

    }
  }

  return EXIT_SUCCESS;
}
