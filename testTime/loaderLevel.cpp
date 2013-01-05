//
//  loaderLevel.cpp
//  testTime
//
//  Created by Florian Gomis on 23/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "loaderLevel.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

loaderLevel::loaderLevel(std::string file)
{
    this->fileUrl = file;
}

loaderLevel::~loaderLevel()
{
    
}

std::vector< std::vector<int> > loaderLevel::returnMap(int &w, int &h)
{
    int ww = 0;
    int hh = 0;
    this->fileUrl = resourcePath()+this->fileUrl;
    
    ifstream fichier(this->fileUrl.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier)  // si l'ouverture a réussi
    {       
        string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {     
            int taille= strlen(ligne.c_str());
            for(int i=0;i<taille;i++)
            {
                if (ligne[i] != ' ' && hh == 0)
                {
                    ww++;
                }
            }
        hh++;
        }

        
        cout << "Nombre de tile largeur : " << ww <<endl;
        cout << "Nombre de tile Hauteur : " << hh <<endl;
        
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
    
    
    m.resize(hh);
	//Each row has h columns of null Tile pointers
	for(int i = 0; i < hh; i++)
	{
        m.at(i).resize(ww, 0);
	}
    
    
    
    w = hh ;
    h = ww ;
    
    //On reset pour rentrer dans le tableau les bon chiffre de level.txt
    ww = 0;
    hh = 0;
    ifstream fichier2(this->fileUrl.c_str(), ios::in);  // on ouvre le fichier en lecture
    
    if(fichier2)  // si l'ouverture a réussi
    {       
        string ligne;
        while(getline(fichier2, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {     
            int taille= strlen(ligne.c_str());
            for(int i=0;i<taille;i++)
            {
                if (ligne[i] != ' ')
                {   
                    // Ici on fait un cast d'int puis on retire -0 pour pouvoir récuperer le int (trouvé la fonction atoi depuis)
                    // this->m[ww][hh] = (int)(ligne[i] - '0');
                    int l = atoi(&ligne[i]);
                    this->m[ww][hh] = l;
                    hh++;
                }
            }

            hh=0;
            ww++;
        }
        fichier2.close();  // on ferme le fichier
    }
    



    return this->m;
}


