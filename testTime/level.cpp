//
//  File.cpp
//  testTime
//
//  Created by Florian Gomis on 22/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "level.h"

#include <vector>
#include "tile.h"

using std::vector;

level::level(string fileUrl)
{
    this->w=0;
    this->h=0;

    ll = new loaderLevel(fileUrl);
    this->m = ll->returnMap(this->w, this->h);
    
    setDimensions(this->w, this->h);
}


level::~level()
{
	
}

int level::getHeight()
{
	return this->h;
}

int level::getWidth()
{
	return this->w;
}

void level::setDimensions(int w, int h)
{
	this->w = w;
	this->h = h;
	
	//w rows
	map.resize(this->w);
	
	//Each row has h columns of null Tile@ pointers
	for(int i = 0; i < this->w; i++)
	{
		this->map.at(i).resize(this->h, 0);
	}
}

void level::addTile(int x, int y, tile* tile)
{
	this->map[x][y] = tile;
}

tile* level::getTile(unsigned int x, unsigned int y)
{
	if(x < this->map.capacity())
	{
		if(y < this->map[x].capacity())
		{
			return this->map[x][y];
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void level::loadLevel()
{
    
}

