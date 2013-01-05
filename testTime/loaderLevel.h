//
//  loaderLevel.h
//  testTime
//
//  Created by Florian Gomis on 23/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_loaderLevel_h
#define testTime_loaderLevel_h

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

class loaderLevel {
public:

    loaderLevel(std::string file);
    ~loaderLevel();
    std::vector< std::vector<int> > returnMap(int &w, int &h);
    
private:
    
    std::string fileUrl;
    std::vector< std::vector<int> > m;
    
};

#endif
