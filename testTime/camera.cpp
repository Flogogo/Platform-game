//
//  camera.cpp
//  testTime
//
//  Created by Florian Gomis on 15/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "camera.h"

camera::camera()
{
    this->view = sf::View(); 
    this->view.zoom(0.8f);
}

void camera::update(sf::Vector2f pos)
{
    this->view.setCenter(pos.x, pos.y);
    //Zoom dezoom de la camera
    this->zoomUnzoom();
    
}
	
void camera::zoomUnzoom()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->view.zoom(1.006);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
       this->view.zoom(0.99);
        
    }

}
sf::View camera::getView()
{
    return this->view;
}