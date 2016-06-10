//
//  AutoSprites.h
//  Baconator
//
//  Created by Thomas Paniagua on 10/13/12.
//  Copyright (c) 2012 LIA. All rights reserved.
//

#ifndef __Baconator__AutoSprites__
#define __Baconator__AutoSprites__

#include <SFML/Graphics.hpp>

using namespace std;
namespace AutoSprites{
class MovingSprite{
public:
    MovingSprite();
    MovingSprite(string path, char switchMode, unsigned short int x, unsigned short int y);
    MovingSprite(sf::Sprite sprt, char switchMode, unsigned short int x, unsigned short int y);

    MovingSprite(string path, unsigned short int x, unsigned short int y);
    MovingSprite(sf::Sprite sprt, unsigned short int x, unsigned short int y);

    void DrawNext(sf::RenderWindow* win);
    void AddAnimation(std::string name, unsigned short int startX, unsigned short int startY, unsigned short int endX, unsigned short int endY, unsigned short int fps );
    bool SetAnimation(std::string name);

};
}

#endif
