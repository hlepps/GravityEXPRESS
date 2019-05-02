#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>

#include "sound.h"
#include "draw.h"
#include "structs.h"
#include "savegame.h"
#include "actions.h"
#include "strange_things.h"
#include "box.h"

using namespace std;

int currlvl = 0;
bool loadMap = true;

bool newlvlload;

int mapsize = 15;


void gameInit()
{
    initStructs();

    cout << "ladowanie..." << endl << endl;

    gamesave.open("save\\save.gexsave");

    cout << "wczytywanie tekstur..." << endl;

    yellowInput.texture.loadFromFile("tex\\yellowinput.png");
    yellowInput.sprite.setTexture(yellowInput.texture);

    yellowBox.texture.loadFromFile("tex\\yellowbox.png");
    yellowBox.sprite.setTexture(yellowBox.texture);

    redInput.texture.loadFromFile("tex\\redinput.png");
    redInput.sprite.setTexture(redInput.texture);

    redBox.texture.loadFromFile("tex\\redbox.png");
    redBox.sprite.setTexture(redBox.texture);

    endGame.texture.loadFromFile("tex\\koniec.png");
    endGame.sprite.setTexture(endGame.texture);

    nextLvl.texture.loadFromFile("tex\\start.png");
    nextLvl.sprite.setTexture(nextLvl.texture);

    lose.texture.loadFromFile("tex\\death.png");
    lose.sprite.setTexture(lose.texture);

    background.texture.loadFromFile("tex\\background.png");
    background.sprite.setTexture(background.texture);

    wall1.texture.loadFromFile("tex\\wall1.png");
    wall1.sprite.setTexture(wall1.texture);


    wall2.texture.loadFromFile("tex\\wall2.png");
    wall2.sprite.setTexture(wall2.texture);

    corner1.texture.loadFromFile("tex\\corner1.png");
    corner1.sprite.setTexture(corner1.texture);

    corner2.texture.loadFromFile("tex\\corner2.png");
    corner2.sprite.setTexture(corner2.texture);

    corner3.texture.loadFromFile("tex\\corner3.png");
    corner3.sprite.setTexture(corner3.texture);

    corner4.texture.loadFromFile("tex\\corner4.png");
    corner4.sprite.setTexture(corner4.texture);

    triple1.texture.loadFromFile("tex\\triple1.png");
    triple1.sprite.setTexture(triple1.texture);

    triple2.texture.loadFromFile("tex\\triple2.png");
    triple2.sprite.setTexture(triple2.texture);

    triple3.texture.loadFromFile("tex\\triple3.png");
    triple3.sprite.setTexture(triple3.texture);

    triple4.texture.loadFromFile("tex\\triple4.png");
    triple4.sprite.setTexture(triple4.texture);




    cout << "wczytano!" << endl << endl;

    cout << "wczytywanie dzwieku..." << endl;





    cout << "wczytano!" << endl << endl;


}


void loadLevel(int lvl, fstream &file)
{
    string temp = "lvl\\lvl" + to_string(lvl) + ".gex";
    file.open(temp.c_str());

    cout << temp;
}





#endif // INIT_H_INCLUDED
