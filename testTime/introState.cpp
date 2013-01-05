//
//  introState.cpp
//  testTime
//
//  Created by Florian Gomis on 20/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//


#include <iostream>
#include "gameEngine.h"
#include "introState.h"


introState introState::m_IntroState;


void introState::Init()
{   
    this->LoadImages();
    
}

void introState::LoadImages()
{
    sf::Texture sprite;
    sprite.loadFromFile(resourcePath()+"Tileset.png");
    textureManager.AddImage(sprite);

    this->tile_herbe = new tile(textureManager.GetImage(0), sf::IntRect(0,0,32,32), true);    
    this->tile_mur = new tile(textureManager.GetImage(0), sf::IntRect(7*32,2*32,32,32), false);        
    this->tile_character = new tile(textureManager.GetImage(0), sf::IntRect(4*32,7*32,32,32), false);
    this->tile_rocher = new tile(textureManager.GetImage(0), sf::IntRect(0*32,7*32,64,64), false);
    
    // On met dans un MAP les 4 textures de mouvement comme ca il suffit de faire une recherche avec les mots clef pour trouver le personnage
    map<string, sf::IntRect> mouvementPerso;
    mouvementPerso.insert ( pair<string,sf::IntRect>("DOWN", sf::IntRect( 0, 0, 31, 61)));
    mouvementPerso.insert ( pair<string,sf::IntRect>("LEFT", sf::IntRect( 0, 62, 31, 61)));
    mouvementPerso.insert ( pair<string,sf::IntRect>("TOP", sf::IntRect( 0, 122, 31, 61)));
    mouvementPerso.insert ( pair<string,sf::IntRect>("RIGHT", sf::IntRect( 0, 192, 31, 61)));
    
    
    this->current_lvl = new level("level1.txt");
    for (int x = 0; x < current_lvl->getWidth(); x++) {
        for (int h = 0; h < current_lvl->getHeight(); h++) {
            if (current_lvl->m[x][h]==0) {
                tile *t = new tile(textureManager.GetImage(0), sf::IntRect(0,0,32,32), true, sf::IntRect(h*32,x*32,32,32));
                current_lvl->addTile(x, h, t);
            }
            if (current_lvl->m[x][h]==1) {
                tile *t = new tile(textureManager.GetImage(0), sf::IntRect(7*32,2*32,32,32), false, sf::IntRect(h*32,x*32,32,32));
                current_lvl->addTile(x, h, t);
            }
        }
    }


}

void introState::Cleanup()
{
    delete this->tile_mur;
}

void introState::Pause()
{
    std::cout << "Pause activé !" << std::endl;
}

void introState::Resume()
{
    std::cout << "Reprise activé !" << std::endl;
}

void introState::HandleEvents(gameEngine* game)
{
    
    while (game->screen->pollEvent(event))
    {
        
        // Close window : exit
        if (event.type == sf::Event::Closed)
        {
            game->Quit();
        }  
        
        // Escape pressed : exit
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            game->Quit();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->pos.x = this->pos.x+10;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->pos.y = this->pos.y+10;            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->pos.y = this->pos.y-10;            
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->pos.x = this->pos.x-10;
        }
    }
}

void introState::Update(gameEngine* game)
{
    this->cam.update(this->pos);
}

void introState::Draw(gameEngine* game)
{
    // Clear screen
    game->screen->clear();
    
    game->screen->setView(this->cam.getView());

    
    // Draw the sprite
    for (int x = 0; x < current_lvl->getWidth(); x++) {
        for (int h = 0; h < current_lvl->getHeight(); h++) {
            if (current_lvl->getTile(x, h)) {
            current_lvl->getTile(x, h)->Draw(h*32, x*32, game->screen);
            }
        }
    }
    
    
    // Update the window
    game->screen->display();

}

