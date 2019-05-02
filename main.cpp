
#include "init.h"

using namespace std;

int wybor;


void makeMap(int tempId, Object mapo[15][15], int y, int x)
{

    switch(tempId)
                {
                case -7:
                    mapo[y][x] = yellowInput;
                    break;
                case -6:
                    mapo[y][x] = yellowBox;
                    addBox(2,x,y);
                    break;
                case -5:
                    mapo[y][x] = lose;

                    break;

                    case -4:
                        mapo[y][x] = redInput;

                        break;

                    case -3:
                        mapo[y][x] = redBox;
                        addBox(1, x, y);
                        break;

                    case -2:
                        mapo[y][x] = endGame;
                        mapo[y][x].action = a_endGame;
                        break;

                    case -1:
                        mapo[y][x] = nextLvl;
                        mapo[y][x].action = a_nextLvl;
                        break;

                    case 0:
                        mapo[y][x] = nothing;
                        break;

                    case 1:
                        mapo[y][x] = background;
                        break;

                    case 2:
                        mapo[y][x] = wall1;
                        break;

                    case 3:
                        mapo[y][x] = wall2;
                        break;

                    case 4:
                        mapo[y][x] = corner1;
                        break;

                    case 5:
                        mapo[y][x] = corner2;
                        break;

                    case 6:
                        mapo[y][x] = corner3;
                        break;

                    case 7:
                        mapo[y][x] = corner4;
                        break;

                    case 8:
                        mapo[y][x] = triple1;
                        break;

                    case 9:
                        mapo[y][x] = triple2;
                        break;

                    case 10:
                        mapo[y][x] = triple3;
                        break;

                    case 11:
                        mapo[y][x] = triple4;
                        break;

                    default:
                        mapo[y][x] = nothing;
                    }

}

int main()
{
    fstream lvlfile;
    Object mapo[15][15];


    gameInit();

    sf::RenderWindow window(sf::VideoMode(64*mapsize, 64*mapsize), "GraviExpress");
    sf::View view(sf::FloatRect(0,0,64*mapsize,64*mapsize));


    sound.setBuffer(box1);
    sound.play();



    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
                window.setView(view);

            if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                        {
                            window.close();
                        }

                    if (event.key.code == sf::Keyboard::W)
                        {
                            moveBox(mapo, 0,loadMap);
                            //switchCheckables(mapo, true, mapsize);
                            //cout << "actual checkable: " << ax << " " << ay << endl;
                            if(currlvl == 0)
                            {
                                wybor = 0;
                            }
                            else wybor = -1;
                        }
                    if (event.key.code == sf::Keyboard::S)
                        {
                            moveBox(mapo, 2,loadMap);
                            //switchCheckables(mapo, false, mapsize);
                            //cout << "actual checkable: " << ax << " " << ay << endl;
                            if(currlvl == 0)
                            {
                                wybor = 1;
                            }
                            else wybor = -1;
                        }
                    if (event.key.code == sf::Keyboard::A)
                        {
                            moveBox(mapo, 3,loadMap);
                        }
                    if (event.key.code == sf::Keyboard::D)
                        {
                            moveBox(mapo, 1,loadMap);
                        }

                    if (event.key.code == sf::Keyboard::O)
                        {
                            loadMap = true;
                            currlvl--;


                        }
                    if (event.key.code == sf::Keyboard::P)
                        {
                            loadMap = true;
                            currlvl++;


                        }
                    if(event.key.code == sf::Keyboard::Space)
                    {
                        cout << wybor;
                        if(wybor == 0)
                        {
                            loadMap = true;
                            currlvl++;
							newlvlload = true;
                        }
                        if(wybor == 1) window.close();

                    }
                }
        }

        window.clear();

        if(currlvl != 0 && loadMap)
        {
            resetBoxes();
            lvlfile.close();
			if (newlvlload)
			{

				music.stop();
				music.openFromFile("muz\\Space.wav");
				music.setLoop(true);
				music.play();
				newlvlload = false;
			}
            loadLevel(currlvl, lvlfile);
            cout << ":" << endl;
            int tempId;

            for(int y = 0; y < mapsize; y++)
            {
                for(int x = 0; x < mapsize; x++)
                {

                    lvlfile >> tempId;
                    cout << tempId << "  ";

                    makeMap(tempId, mapo, y, x);

                    tempId = NULL;

                    mapo[y][x].sprite.setPosition(x*64, y*64);
                }
                cout << endl;
            }
            findCheckable(mapo, mapsize);
            cout << "actual checkable: " << ax << " " << ay << endl;
            loadMap = false;

        }
        else if (loadMap)
        {
            resetBoxes();
            lvlfile.close();

            music.stop();
            music.openFromFile("muz\\Menu.wav");
            music.setLoop(true);
            music.play();
            loadLevel(currlvl, lvlfile);
            cout << ":" << endl;
            int tempId;

            for(int y = 0; y < mapsize; y++)
            {
                for(int x = 0; x < mapsize; x++)
                {

                    lvlfile >> tempId;
                    cout << tempId << "  ";
                    makeMap(tempId, mapo, y, x);

                    tempId = NULL;

                    mapo[y][x].sprite.setPosition(x*64, y*64);
                }
                cout << endl;
            }
            findCheckable(mapo, mapsize);
            cout << "actual checkable: " << ax << " " << ay << endl;
            loadMap = false;
        }




        for(int y = 0; y < mapsize; y++)
            {
                for(int x = 0; x < mapsize; x++)
                {
                    window.draw(mapo[y][x].sprite);
                }
            }


        checkForWin(loadMap, currlvl, newlvlload);



        window.display();
    }

    return 0;
}

