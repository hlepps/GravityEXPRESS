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
#include <conio.h>
#include <cstdlib>

#include "structs.h"

int mapsize = 15;


void loadLVL(fstream &file)
{
    file.close();
    string temp = "lvl\\lvl.gex";
    file.open("lvl\\lvl.gex");

    cout << temp << endl;
}

void gameInit()
{
    initStructs();

    cout << "ladowanie..." << endl << endl;



    cout << "wczytywanie tekstur..." << endl;

    cursor.texture.loadFromFile("tex\\kursor.png");
    cursor.sprite.setTexture(cursor.texture);



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


int aktI;
Object akt[15][15];

void put(Object mapo[15][15], int x, int y)
{
    Object temp;
    temp = akt[0][0];
    temp.sprite.setPosition(mapo[y][x].sprite.getPosition().x, mapo[y][x].sprite.getPosition().y );
    mapo[y][x] = temp;
}

void goleft()
{
    aktI--;
    if(aktI < -7) aktI = 11;
    if(aktI > 11) aktI = -7;
}

void goright()
{
    aktI++;
    if(aktI < -7) aktI = 11;
    if(aktI > 11) aktI = -7;
}


#endif // INIT_H_INCLUDED
