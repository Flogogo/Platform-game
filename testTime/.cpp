//
//  Player.cpp
//  testTime
//
//  Created by Florian Gomis on 10/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;

Player::Player()
{
}

Player::Player(string urlImg, int posiX, int posiY, map<string, sf::IntRect> mapMov, spell *currentSpell)
{
    this->test2 = new tile();
    this->position.x = posiX;
    this->position.y = posiY;
    this->velocity = 1;
    // Load a sprite to display
    if (!this->texure.loadFromFile(resourcePath() + urlImg))
        return EXIT_FAILURE;
    this->sprite.setTexture(this->texure);
    this->mapMov = mapMov;
    
    map<string, sf::IntRect>::iterator it = mapMov.find("DOWN");
    this->sprite.setTextureRect(it->second);    

    
    this->sprite.setOrigin(this->sprite.getGlobalBounds().width/2 , this->sprite.getGlobalBounds().height/2);
}

int Player::getX()
{
    return this->position.x;   
}
int Player::getY()
{
    return this->position.y;
}

void Player::Draw(sf::RenderWindow* rw)
{
    for (vector<spell*>::iterator it = this->currentSpell.begin(); it!= this->currentSpell.end(); it++) 
    {
        if((*it)->enCour ==true)
        {
            rw->draw((*it)->sprite);
        }
    }
    
    this->sprite.setPosition(this->position.x, this->position.y);
    rw->draw(this->sprite);
}

void Player::setPosX(int newX)
{
    this->position.x = newX;
}
void Player::setPosY(int newY)
{
    this->position.y = newY;
}

void Player::mouvement(level *currentLevel)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->etat = DOWN;
        this->newPosition = this->position;
        this->newPosition.y += this->velocity;
        
        this->test2 = currentLevel->getTile((this->newPosition.y+this->boundBox.height/2)/32, (this->newPosition.x)/32);
        
        if (!this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.y = this->position.y;
        }
        if (this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.y  = this->newPosition.y;

        }
        
        map<string, sf::IntRect>::iterator it = this->mapMov.find("DOWN");
        this->sprite.setTextureRect(it->second);
        
        //this->setPosY(this->getY()+this->velocity);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->etat = TOP;
        this->newPosition = this->position;
        this->newPosition.y -= this->velocity;
        
        this->test2 = currentLevel->getTile((this->newPosition.y-this->boundBox.height/2)/32, (this->newPosition.x)/32);
        
        if (!this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.y = this->position.y;
        }
        if (this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.y  = this->newPosition.y;
        }
        
        map<string, sf::IntRect>::iterator it = this->mapMov.find("TOP");
        this->sprite.setTextureRect(it->second);
        
        //this->setPosY(this->getY()-this->velocity);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
       this->etat = RIGHT;
        this->newPosition = this->position;
        this->newPosition.x += this->velocity;
        
        this->test2 = currentLevel->getTile((this->newPosition.y)/32, (this->newPosition.x+this->boundBox.width/2)/32);
        
        if (!this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.x = this->position.x;
        }
        if (this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.x  = this->newPosition.x;
        }

        map<string, sf::IntRect>::iterator it = this->mapMov.find("RIGHT");
        this->sprite.setTextureRect(it->second);
        
        //this->setPosX(this->getX()+this->velocity);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->etat = LEFT;
        this->newPosition = this->position;
        this->newPosition.x -= this->velocity;
        
        this->test2 = currentLevel->getTile((this->newPosition.y)/32, (this->newPosition.x-this->boundBox.width/2)/32);
        
        if (!this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.x = this->position.x;
        }
        if (this->test2->getPassable() && this->test2->containPlayer(this))
        {
            this->position.x  = this->newPosition.x;
        }

        map<string, sf::IntRect>::iterator it = this->mapMov.find("LEFT");
        this->sprite.setTextureRect(it->second);
        
        //this->setPosX(this->getX()-this->velocity);
    }
    
    // a garder pour rotation de l'arme a l'attaque !
    /*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        float rotation = 3;
        this->sprite.setRotation(this->sprite.getRotation()+rotation);
    }
    else {
        this->sprite.setRotation(0);
    }
    */
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (this->currentSpell.size() < 1)
        {
            this->currentSpell.push_back(new spell("images.jpeg", sf::IntRect(0,0, 25, 27), 10, this, 6, true, 20));
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        velocity = 10;
    }
    else 
    {
        velocity = 5;
    }
}

void Player::update(level *currentLevel)
{    
    this->mouvement(currentLevel);
    //this->currentTile = currentLevel->getTile(this->position.x, this->position.y);
    
    this->boundBox.top = this->position.y;
    this->boundBox.left = this->position.x;
    this->boundBox.width = this->sprite.getGlobalBounds().width;
    this->boundBox.height = this->sprite.getGlobalBounds().height;
    
   // this->boundBoxVisu.setTextureRect(this->boundBox);
    this->boundBoxVisu.setPosition(this->boundBox.left, this->boundBox.top);
    this->boundBoxVisu.setSize(sf::Vector2f(1, 1));
    
    this->currentTile = currentLevel->getTile(this->position.y/32, this->position.x/32);

    //Voir ou se trouve la case testé lors d'un mouvement
    //if(this->test2)
    //this->test2->setcolor(sf::Color::Blue);


    for (vector<spell*>::iterator it = this->currentSpell.begin(); it!= this->currentSpell.end(); it++) 
    {
        
        (*it)->update(currentLevel);
        
        if((*it)->enCour==false)
        {
            this->currentSpell.erase(this->currentSpell.begin());
            it=this->currentSpell.end()-1;
            //remove(this->currentSpell.begin(), this->currentSpell.end(), it);
        }
        
    }
    
    
    
    for (vector< vector<tile*> >::iterator it = currentLevel->map.begin(); it!=currentLevel->map.end(); it++) 
    {
        for (vector<tile*>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++) 
        {
            if (!(*it2)->getPassable()) 
            {
                // Colorier les Tile non franchissable
                //(*it2)->setcolor(sf::Color::Red);
            }
            
            
        }
    }
    
}




