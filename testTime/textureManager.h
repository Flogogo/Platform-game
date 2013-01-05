//
//  textureManager.h
//  testTime
//
//  Created by Florian Gomis on 21/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_textureManager_h
#define testTime_textureManager_h

#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

class textureManager {
    
private:
    std::vector<sf::Texture> imageList;

public:
	textureManager();
	~textureManager();

    void loadTexture(std::string adresseFile);
	void AddImage(sf::Texture image);
	sf::Texture& GetImage(int index);
    
};


#endif
