//
//  tile.cpp
//  testTime
//
//  Created by Florian Gomis on 21/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "tile.h"
#include "SFML/Graphics.hpp"

tile::tile()
{
}

tile::tile(sf::Texture& texture, sf::IntRect rect, bool p){
    this->baseSprite.setTexture(texture);
    this->baseSprite.setTextureRect(rect);
    this->passable = p;
    
    //Ici on met la largeur et longueur de la boundbox pour la collision plus tard
    this->rect.width = this->baseSprite.getGlobalBounds().width;
    this->rect.height = this->baseSprite.getGlobalBounds().height;

}

tile::tile(sf::Texture& texture, sf::IntRect rect, bool p, sf::IntRect box){
    this->baseSprite.setTexture(texture);
    this->baseSprite.setTextureRect(rect);
    this->passable = p;
    
    //Ici on met la largeur et longueur de la boundbox pour la collision plus tard
    this->rect.width = this->baseSprite.getGlobalBounds().width;
    this->rect.height = this->baseSprite.getGlobalBounds().height;}

tile::~tile(){
}

void tile::Draw(int x, int y, sf::RenderWindow* rw)
{
    this->baseSprite.setPosition(x, y);
    this->x = x;
    this-> y = y;
    
    // On met ici la position du rectangle pour la boundBox
    this->rect.top = y;
    this->rect.left = x;
    rw->draw(baseSprite);
}

bool tile::getPassable()
{
    if (this->passable == false)
    {
        return false;
    }
        else 
    {
        return true;    
    }
}


void tile::setcolor(sf::Color color)
{
    this->baseSprite.setColor(color);
}




bool tile::containPlayer(sf::Sprite *sprite)
{
    if(this->rect.intersects(sf::IntRect(sprite->getPosition().x, sprite->getPosition().y, sprite->getGlobalBounds().width,sprite->getGlobalBounds().height)))
        return true;
    else
        return false;
}