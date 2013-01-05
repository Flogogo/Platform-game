//
//  gameEngine.cpp
//  testTime
//
//  Created by Florian Gomis on 20/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "gameEngine.h"
#include "gameState.h"
#include <iostream>

void gameEngine::Init(int width, int height, const string titre)
{
    this->screen = new sf::RenderWindow(sf::VideoMode(width, height), titre);
    this->screen->setFramerateLimit(60);
    m_running = true;
}

void gameEngine::Cleanup()
{
    // cleanup the all states
	while ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// switch back to windowed mode so other 
	// programs won't get accidentally resized
    
    this->screen = new sf::RenderWindow(sf::VideoMode(800, 600), "Default Title");
	  
    this->screen->close();
}

void gameEngine::ChangeState(gameState* state)
{
    // cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void gameEngine::PushState(gameState* state)
{
    // pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}
    
	// store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void gameEngine::PopState()
{
    // cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}
    
	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void gameEngine::HandleEvents()
{
    // let the state handle events
	states.back()->HandleEvents(this);
}

void gameEngine::Update()
{
    // let the state handle events
	states.back()->Update(this);
}

void gameEngine::Draw()
{
 	// let the state handle events
    
	states.back()->Draw(this);   
}
