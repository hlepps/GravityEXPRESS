#ifndef SAVEGAME_H_INCLUDED
#define SAVEGAME_H_INCLUDED

#include "init.h"

fstream gamesave;


void saveGame(int number)
{
    gamesave << number;
}

int loadGame()
{
    int number;
    gamesave >> number;
    return number;
}

#endif // SAVEGAME_H_INCLUDED
