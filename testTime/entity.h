//
//  entity.h
//  testTime
//
//  Created by Florian Gomis on 01/01/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_entity_h
#define testTime_entity_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"
#include "level.h"

class entity {
protected:
    sf::Sprite baseSprite; // Sprite of the entity
    int velocity; // Vel of the entity
    sf::Vector2f pos; // Position of the entity
    
public:
    
    // Argument ...
    // map<string, sf::IntRect> tabPerso, sf::Vector2f posPerso, int velocity
    
    virtual entity()= 0;
    virtual ~entity();= 0;
    
    virtual void draw(sf::RenderWindow* renderWindow)= 0;
    virtual void update(level *currentLevel)= 0;
};


#endif
