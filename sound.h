#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include "init.h"

using namespace std;


sf::SoundBuffer box1;
sf::SoundBuffer box2;



sf::Sound sound;

sf::Music music;
sf::Music boxesMusic;

void initSound()
{
    box2.loadFromFile("muz\\box1.wav");
    box2.loadFromFile("muz\\box2.wav");
}





#endif // SOUND_H_INCLUDED
