#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "gameEngine.h"
#include "introState.h"
#include "ResourcePath.hpp"

int main (int argc, const char * argv[])
{
    
    gameEngine game;
    
	// initialize the engine
    game.Init(800, 600, "1st Platformer Game");
    
    //La on envoie l'état que l'on veut
    game.PushState(introState::Instance());
    
    // main loop
	while ( game.Running() )
	{
		game.HandleEvents();
		game.Update();
		game.Draw();
	}
    
	return 0;
}
