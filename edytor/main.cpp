#include "init.h"

using namespace std;

bool won = false;

int numer = 1;
int x;
int y;
char tura = 'o';
int ruchx;
int ruchy;
int punktx;
int punkto;



bool operator == (sf::Sprite a, sf::Sprite b)
{
   if(a == b)
     return true;
   else
     return false;
}


int kursorx = 0;
int kursory = 0;

int kursorxl = 0;
int kursoryl = 0;



sf::Sprite tabS[8][8];

int stan = -1;

Object mapo[15][15];




fstream plik;


sf::Font font;
sf::Text Ttura;

string sTura;

void makeMap(int tempId, Object mapo[15][15], int y, int x)
{

    switch(tempId)
                {
                case -7:
                    mapo[y][x] = yellowInput;
                    break;
                case -6:
                    mapo[y][x] = yellowBox;

                    break;
                case -5:
                    mapo[y][x] = lose;

                    break;

                    case -4:
                        mapo[y][x] = redInput;

                        break;

                    case -3:
                        mapo[y][x] = redBox;

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
    gameInit();
    loadLVL(plik);
    int tempId = 0;
    for(int y = 0; y < mapsize; y++)
                    {
                        for(int x = 0; x < mapsize; x++)
                        {

                            plik >> tempId;
                            //cout << "  " << tempId << "  ";
                            makeMap(tempId, mapo, y, x);

                            tempId = NULL;

                            mapo[y][x].sprite.setPosition(x*64, y*64);
                        }
                        cout << endl;
                    }

    font.loadFromFile("font.ttf");
    Ttura.setFont(font);
    Ttura.setCharacterSize(48);
    Ttura.setPosition(0, 960);
    Ttura.setColor(sf::Color::Black);


    sf::RenderWindow oknoAplikacji( sf::VideoMode( 960, 1024, 32 ), "GEX edytor" );

    while(oknoAplikacji.isOpen())
    {
        sTura = "   | Q Wybor W | O Load | P Save";

        Ttura.setString(sTura);

        sf::Event zdarzenie;
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                 kursory--;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                 kursory++;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
                 kursorx--;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
                 kursorx++;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Q )
                 goleft();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Space )
                 put(mapo, kursorx, kursory);

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::W )
                 goright();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::O )
            {
                loadLVL(plik);

                for(int y = 0; y < mapsize; y++)
                    {
                        for(int x = 0; x < mapsize; x++)
                        {

                            plik >> tempId;
                            cout << "  " << tempId << "  ";
                            makeMap(tempId, mapo, y, x);

                            tempId = NULL;

                            mapo[y][x].sprite.setPosition(x*64, y*64);
                        }
                        cout << endl;
                    }
            }

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::P )
            {


                 loadLVL(plik);

                for(int y = 0; y < mapsize; y++)
                    {
                        for(int x = 0; x < mapsize; x++)
                        {

                            plik << mapo[y][x].id;
                            plik << " ";
                            cout << "  " << tempId << "  ";


                            tempId = NULL;


                        }
                        cout << endl;
                    }

            }


            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();

        }

        oknoAplikacji.clear( sf::Color::White );


        for(int i = 0; i < 15; i++)
        {
            for(int y = 0; y < 15; y++)
            {
                oknoAplikacji.draw(mapo[y][i].sprite);
            }
        }

        makeMap(aktI, akt, 0, 0);
        akt[0][0].sprite.setPosition(0, 960);
        oknoAplikacji.draw(akt[0][0].sprite);

        cursor.sprite.setPosition(kursorx*64, kursory*64);

        oknoAplikacji.draw(cursor.sprite);

        oknoAplikacji.draw(Ttura);

        oknoAplikacji.display();




    }

	return(0);
}
