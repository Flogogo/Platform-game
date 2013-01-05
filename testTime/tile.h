//
//  tile.h
//  testTime
//
//  Created by Florian Gomis on 21/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_tile_h
#define testTime_tile_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"
class Player;

class tile 
{
private:
    
public:
    sf::Sprite baseSprite;

    
    tile();
    tile(sf::Texture& texture, sf::IntRect rect, bool p);
    tile(sf::Texture& texture, sf::IntRect rect, bool p, sf::IntRect box);

    ~tile();

    void Draw(int x, int y, sf::RenderWindow* rw);
    void Draw(sf::RenderWindow* rw);
    
    bool getPassable();
    
    bool passable;
    
    bool containPlayer(sf::Sprite *sprite);

    float x, y;
    bool containPlayer(Player *joueur);
    void setcolor(sf::Color color);
    sf::IntRect rect;
};

#endif
