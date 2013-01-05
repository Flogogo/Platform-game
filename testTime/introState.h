//
//  introState.h
//  testTime
//
//  Created by Florian Gomis on 20/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_introState_h
#define testTime_introState_h

#include "textureManager.h"
#include "tile.h"
#include "gameState.h"
#include "level.h"
#include "camera.h"

class introState : public gameState
{
public:
	void Init();
	void Cleanup();
    
	void Pause();
	void Resume();
    
	void HandleEvents(gameEngine* game);
	void Update(gameEngine* game);
	void Draw(gameEngine* game);
    
	static introState* Instance() {
		return &m_IntroState;
	}
    
protected:
	
    introState() { }
    
    camera cam;
    sf::Vector2f pos; 
    
    static introState m_IntroState;
    sf::Vector2f positionPerso;
    level *current_lvl;
    level *current_pos;
    loaderLevel* ll;
    textureManager textureManager;
	void LoadImages();
	
    // Differente Tile 
    tile* tile_mur;
    tile* tile_character;
    tile* tile_herbe;
    tile* tile_rocher;
    
    // Process events (Recuperation souris et clavier
    sf::Event event;


};

#endif
