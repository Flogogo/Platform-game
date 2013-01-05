//
//  textureManager.cpp
//  testTime
//
//  Created by Florian Gomis on 21/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "textureManager.h"
#include <vector>

textureManager::textureManager()
{
}

textureManager::~textureManager()
{
}


void textureManager::AddImage(sf::Texture image)
{
	imageList.push_back(image);
}

sf::Texture& textureManager::GetImage(int index)
{
	return this->imageList[index];
}
