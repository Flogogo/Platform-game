//
//  moteurGraphique.h
//  testTime
//
//  Created by Florian Gomis on 21/11/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef testTime_moteurGraphique_h
#define testTime_moteurGraphique_h

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

class moteurGraphique // Déclaration de base de la classe, jusque là rien de bien surprenant.
{
public:
    
	moteurGraphique(int largeur_p, int hauteur_p, int bitsParPixel_p, std::string titre_p, int rouge = 0, int vert = 0, int bleu = 0);
	moteurGraphique(int largeur_p, int hauteur_p, int bitsParPixel_p, std::string titre_p, std::string image);	
    
    sf::RenderWindow *getEventConfig;
    
    void changerFond(int rouge, int vert, int bleu);
	void changerFond(std::string image);
	void supprimerFond();
    void afficherFrame();
    
    void ajouterSprite(std::string nom, std::string image, ZRectangle cadrage = NULL, int x = 0, int y = 0, Rang rang = DESSUS);
    void supprimerSprite(std::string nom, Rang rang = NULL);
    void changerPositionSprite(std::string nom, Rang rang = NULL, int x, int y, Rang nouveau_rang = NULL);
    void changerImageSprite(std::string nom, Rang rang = NULL, std::string image, ZRectangle cadrage = NULL, Rang nouveau_rang = NULL);

    
    ~moteurGraphique();
    
private:
    
    sf::RenderWindow *application;
};

#endif
