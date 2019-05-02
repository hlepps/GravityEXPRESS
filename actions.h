#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include "init.h"

int ax = 0, ay = 0;

void makeAction(Object object, sf::RenderWindow &window, char pressed)
{
    if(object.action.what == "next lvl")
    {

    }
    if(object.action.what == "exit")
    {
        window.close();
    }

}

void findCheckable(Object mapo[15][15], int mapsize)
{

    bool done = false;

    for(int y = 0; y < mapsize; y++)
            {
                for(int x = 0; x < mapsize; x++)
                {

                    if(mapo[y][x].action.checkable == true)
                    {
                        cout << "found checkable!" << endl;
                        ax = x;
                        ay = y;
                        done = true;
                        break;

                    }
                    else
                    {
                        cout << "No checkable at " << x << " " << y << endl;
                        cout << mapo[y][x].action.what << endl;
                    }
                    if(done)break;
                }
                if(done)break;
            }
            done = false;
}

void switchCheckables(Object mapo[15][15], bool up, int mapsize)
{
    bool done;
    int oay = ay;
    int oax = ax+1;
    cout << oax << endl << oay << endl;
    if(up)
    {
        int times = 0;
        for(int y = oay; y > 0; y--)
            {
                for(int x = oax; x > 0; x--)
                {

                    if(mapo[y][x].action.checkable == true)
                    {
                        cout << "found checkable!" << endl;
                        ax = x;
                        ay = y;
                        done = true;
                        break;

                    }
                    if(x < 1) {oax = mapsize; times++; cout << "ended xses" << endl;}
                    if(y < 1) {oay = mapsize; times++; cout << "ended yses" << endl;}

                    if(times >= 5 || done) break;
                }
                if(times >= 5 || done) break;
            }
            done = false;
            times = 0;
    }
    else if (!up)
    {
        int times = 0;
        int x;
        for(int y = oay; y < mapsize; y++)
            {



                for(x = oax; x < mapsize; x++)
                {
                    if(mapo[y][x].action.checkable == true)
                    {
                        cout << "found checkable!" << endl;
                        ax = x;
                        ay = y;
                        done = true;
                        break;

                    }
                    if(x >= mapsize - 1)
                    {
                        oax = 0; x = 0; times++; cout << "ended xses" << endl;
                    }
                    cout << x << endl << y << endl;


                    if(times >= 15 || done) break;
                }
                if(y >= mapsize - 1)
                {
                    y = 0;
                    oay = 0;
                    times++;
                    cout << "ended yses" << endl;
                }

                cout << x << endl << y << endl;
                if(times >= 15 || done) break;
            }
            done = false;
            times = 0;
    }

}

#endif // ACTIONS_H_INCLUDED
