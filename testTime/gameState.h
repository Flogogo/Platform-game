//
//  gameState.h
//  testTime
//
//  Created by Florian Gomis on 20/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_gameState_h
#define testTime_gameState_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"
#include "gameEngine.h"

class gameState
{
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;
    
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    
    virtual void HandleEvents(gameEngine* game) = 0;
    virtual void Update(gameEngine* game) = 0;
    virtual void Draw(gameEngine* game) = 0;
    
    void ChangeState(gameEngine* game, gameState* state)
    {
        game->ChangeState(state);
    }
    
protected:
    gameState() { }
};

#endif
