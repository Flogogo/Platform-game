//
//  camera.h
//  testTime
//
//  Created by Florian Gomis on 14/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_camera_h
#define testTime_camera_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

class camera 
{
private:
    
    sf::View view;
    
public:
    
    camera();
    void update(sf::Vector2f pos);
    void zoomUnzoom();
    sf::View getView();
    
};


#endif
