#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "init.h"
using namespace std;

struct Action
{
    string when;
    string what;
    bool movable;
    bool checkable;
};

Action a_nextLvl;
Action a_endGame;
Action a_static;
Action a_player;


struct Object{

    sf::Sprite sprite;
    sf::Texture texture;
    int x;
    int y;
    Action action;
    bool box;
    bool solid;
    bool input;
    bool lose;
    string color;

};

Object yellowInput;
Object yellowBox;
Object lose;
Object redInput;
Object redBox;
Object endGame;
Object nextLvl;

Object nothing;

Object background;
Object wall1;
Object wall2;
Object corner1;
Object corner2;
Object corner3;
Object corner4;
Object triple1;
Object triple2;
Object triple3;
Object triple4;

void initStructs()
{
    yellowInput.input = true;
    yellowInput.solid = true;
    yellowInput.color = "yellow";

    yellowBox.box = true;
    yellowBox.solid = true;
    yellowBox.color = "yellow";

    lose.solid = true;
    lose.lose = true;

    redInput.input = true;
    redInput.solid = true;
    redInput.color = "red";

    redBox.box = true;
    redBox.solid = true;
    redBox.color = "red";

    a_endGame.movable = false;
    a_endGame.checkable = true;
    a_endGame.when = "pressed space";
    a_endGame.what = "exit";

    a_nextLvl.movable = false;
    a_nextLvl.checkable = true;
    a_nextLvl.when = "pressed space";
    a_nextLvl.what = "next lvl";

    a_static.movable = false;
    a_static.checkable = false;
    a_static.when = "never";
    a_static.what = "nothing";

    a_player.movable = true;
    a_player.checkable = false;
    a_player.when = "pressed move button";
    a_player.what = "moves";

    endGame.action = a_endGame;
    nextLvl.action = a_nextLvl;

    nothing.action = a_static;

    background.action = a_static;
    wall1.action = a_static;
    wall2.action = a_static;
    corner1.action = a_static;
    corner2.action = a_static;
    corner3.action = a_static;
    corner4.action = a_static;
    triple1.action = a_static;
    triple2.action = a_static;
    triple3.action = a_static;
    triple4.action = a_static;

    background.solid = false;
    wall1.solid = true;
    wall2.solid = true;
    corner1.solid = true;
    corner2.solid = true;
    corner3.solid = true;
    corner4.solid = true;
    triple1.solid = true;
    triple2.solid = true;
    triple3.solid = true;
    triple4.solid = true;
}

#endif // STRUCTS_H_INCLUDED
