//
//  gameEngine.h
//  testTime
//
//  Created by Florian Gomis on 20/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_gameEngine_h
#define testTime_gameEngine_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"
#include <vector>

using namespace std;

class gameState;

class gameEngine
{
public:

    void Init(int width, int height, const string titre);
    void Cleanup();
    
    void ChangeState(gameState* state);
    void PushState(gameState* state);
    void PopState();
    
    void HandleEvents();
    void Update();
    void Draw();
    
    bool Running() { return m_running; }
    void Quit() { m_running = false; }
    
    sf::RenderWindow *screen;
    
private:
    
    // La pile des états
    std::vector<gameState*> states;
    
    bool m_running;
};


#endif
