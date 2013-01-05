//
//  level.h
//  testTime
//
//  Created by Florian Gomis on 22/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_level_h
#define testTime_level_h

#include <vector>
#include <iostream>
#include "tile.h"
#include "loaderLevel.h"
#include "textureManager.h"

using namespace std;
class level
{
public:
    level(string fileUrl);
	~level();
	
	void addTile(int x, int y, tile* tile);
	tile* getTile(unsigned int x, unsigned int y);
	
	void loadLevel();
	
	int getWidth();
	int getHeight();
	
    std::vector< std::vector<int> > m;
	vector<vector<tile*> > map;

private:	
    //A 2D array of Tile pointers

    loaderLevel* ll;
    
	//Width and height of level (in tiles)
	int w;
	int h;
	
	void setDimensions(int w, int h);
};


#endif
