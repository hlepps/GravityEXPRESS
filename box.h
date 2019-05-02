#ifndef BOX_H_INCLUDED
#define BOX_H_INCLUDED

#include "init.h"



vector <Object> boxes;
int boxnumber = 0;
int boxArray[15][15];
Object objectBoxArray[15][15];

void checkForWin(bool & loadMap, int & currlvl, bool newlvl)
{
    if(boxes.size() <= 0)
    {
		newlvl = true;
        system("cls");
        loadMap = true;
        currlvl++;
		
    }
}

void box_to_object(int mapsize)
{
    for(int y = 0; y < mapsize; y++)
    {
        for(int x = 0; x < mapsize; x++)
        {
            switch(boxArray[y][x])
            {
            case 1:
                objectBoxArray[y][x] = redBox;
                break;
            }
        }
    }
}

void addBox(int box, int x, int y)
{
    boxnumber++;
    Object tempBox;
    if(box == 1) tempBox = redBox;
    if(box == 2) tempBox = yellowBox;
    tempBox.x = x;
    tempBox.y = y;
    boxes.push_back(tempBox);

}

void resetBoxes()
{
    boxnumber = 0;
    boxes.clear();
}

void check(Object mapo[15][15])
{
    for(int i = 0; i < boxes.size(); i++)
    {
        mapo[boxes[i].y][boxes[i].x].sprite.setPosition(boxes[i].x * 64.0f, boxes[i].y * 64.0f);
    }
}

bool isThisLose(Object mapo[15][15], int dir, int i)
{
    cout << "checking for end..." << endl;
    switch(dir)
    {
    case 0:
        if(mapo[boxes[i].y - 1][boxes[i].x].lose == true)
            {
                cout << "there is lose!" << endl;
                return true;
            }
            else return false;
        break;

    case 1:
        if(mapo[boxes[i].y][boxes[i].x + 1].lose == true)
            {
                cout << "there is lose!" << endl;
                return true;
            }
            else return false;
        break;

    case 2:
        if(mapo[boxes[i].y + 1][boxes[i].x].lose == true)
            {
                cout << "there is end!" << endl;
                return true;
            }
            else return false;
        break;

    case 3:
        if(mapo[boxes[i].y][boxes[i].x - 1].lose == true)
            {
                cout << "there is lose!" << endl;
                return true;
            }
            else return false;
        break;
    }
}

bool isThisInput(Object mapo[15][15], int dir, int i, string color)
{
    cout << "checking for end..." << endl;
    switch(dir)
    {
    case 0:
        if(mapo[boxes[i].y - 1][boxes[i].x].input == true && mapo[boxes[i].y - 1][boxes[i].x].color == color)
            {
                cout << "there is end!" << endl;
                return true;
            }
            else return false;
        break;

    case 1:
        if(mapo[boxes[i].y][boxes[i].x + 1].input == true && mapo[boxes[i].y][boxes[i].x + 1].color == color)
            {
                cout << "there is end!" << endl;
                return true;
            }
            else return false;
        break;

    case 2:
        if(mapo[boxes[i].y + 1][boxes[i].x].input == true && mapo[boxes[i].y + 1][boxes[i].x].color == color)
            {
                cout << "there is end!" << endl;
                return true;
            }
            else return false;
        break;

    case 3:
        if(mapo[boxes[i].y][boxes[i].x - 1].input == true && mapo[boxes[i].y ][boxes[i].x - 1].color == color)
            {
                cout << "there is end!" << endl;
                return true;
            }
            else return false;
        break;
    }
}

void checkForInput(Object mapo[15][15], int dir, int i, string color)
{
    if(isThisInput(mapo,dir,i, color))
                        {
                            Object temp;
                            temp = background;
                            temp.sprite.setPosition(boxes[i].x * 64.0f, boxes[i].y * 64.0f);
                            mapo[boxes[i].y][boxes[i].x] = temp;
                            cout << "erasing..." << endl;
                            boxes.erase(boxes.begin() + i);
                            cout << "erased!" << endl;

                        }
}

void checkForLose(Object mapo[15][15], int dir, int i, bool & loadMap)
{
    if(isThisLose(mapo,dir,i))
            {
                    cout << "u lost" << endl;
                     loadMap = true;

            }
}

void checkForBlock(Object mapo[15][15], int dir, int i, string color)
{

    int j = 1;
    int done = boxes.size() * 4;
    cout << done << endl;
    while(true)
    {



        switch(dir)
        {
        case 0:
            if(mapo[boxes[i].y - j][boxes[i].x].solid == false)
                {
                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << "free space up" << endl;

                    mapo[boxes[i].y - j][boxes[i].x].sprite.setPosition(boxes[i].x*64.0f, boxes[i].y*64.0f);
                    mapo[boxes[i].y][boxes[i].x] = mapo[boxes[i].y - j][boxes[i].x];

                    cout << "deleted box from: " << boxes[i].x << " " << boxes[i].y << endl;



                    boxes[i].sprite.setPosition(mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().x , mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().y - 64.0f);
                    mapo[boxes[i].y - j][boxes[i].x] = boxes[i];
                    cout << "moved box to: " << boxes[i].x << " " << boxes[i].y - j << endl;
                    cout << boxes[i].sprite.getPosition().x << " " << boxes[i].sprite.getPosition().y << endl;


                    boxes[i].y--;


                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().x << " " << mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().y << endl;

                }
            else done--;
            break;

        case 1:
            if(mapo[boxes[i].y][boxes[i].x + j].solid == false)
                {
                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << "free space up" << endl;

                    mapo[boxes[i].y][boxes[i].x + j].sprite.setPosition(boxes[i].x*64.0f, boxes[i].y*64.0f);
                    mapo[boxes[i].y][boxes[i].x] = mapo[boxes[i].y][boxes[i].x + j];

                    cout << "deleted box from: " << boxes[i].x << " " << boxes[i].y << endl;



                    boxes[i].sprite.setPosition(mapo[boxes[i].y][boxes[i].x + j].sprite.getPosition().x + 64.0f , mapo[boxes[i].y][boxes[i].x + j].sprite.getPosition().y);
                    mapo[boxes[i].y][boxes[i].x + j] = boxes[i];
                    cout << "moved box to: " << boxes[i].x + j << " " << boxes[i].y << endl;
                    cout << boxes[i].sprite.getPosition().x << " " << boxes[i].sprite.getPosition().y << endl;


                    boxes[i].x++;


                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << mapo[boxes[i].y][boxes[i].x + j].sprite.getPosition().x << " " << mapo[boxes[i].y][boxes[i].x + j].sprite.getPosition().y << endl;

                }
            else done--;
            break;

        case 2:
            if(mapo[boxes[i].y + j][boxes[i].x].solid == false)
                {
                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << "free space up" << endl;

                    mapo[boxes[i].y + j][boxes[i].x].sprite.setPosition(boxes[i].x*64.0f, boxes[i].y*64.0f);
                    mapo[boxes[i].y][boxes[i].x] = mapo[boxes[i].y + j][boxes[i].x];

                    cout << "deleted box from: " << boxes[i].x << " " << boxes[i].y << endl;



                    boxes[i].sprite.setPosition(mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().x , mapo[boxes[i].y + j][boxes[i].x].sprite.getPosition().y + 64.0f);
                    mapo[boxes[i].y + j][boxes[i].x] = boxes[i];
                    cout << "moved box to: " << boxes[i].x << " " << boxes[i].y + j << endl;
                    cout << boxes[i].sprite.getPosition().x << " " << boxes[i].sprite.getPosition().y << endl;


                    boxes[i].y++;


                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().x << " " << mapo[boxes[i].y - j][boxes[i].x].sprite.getPosition().y << endl;

                }
            else done--;
            break;

        case 3:
            if(mapo[boxes[i].y][boxes[i].x - j].solid == false)
                {
                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << "free space up" << endl;

                    mapo[boxes[i].y][boxes[i].x - j].sprite.setPosition(boxes[i].x*64.0f, boxes[i].y*64.0f);
                    mapo[boxes[i].y][boxes[i].x] = mapo[boxes[i].y][boxes[i].x - j];

                    cout << "deleted box from: " << boxes[i].x << " " << boxes[i].y << endl;



                    boxes[i].sprite.setPosition(mapo[boxes[i].y][boxes[i].x - j].sprite.getPosition().x - 64.0f , mapo[boxes[i].y][boxes[i].x - j].sprite.getPosition().y);
                    mapo[boxes[i].y][boxes[i].x - j] = boxes[i];
                    cout << "moved box to: " << boxes[i].x - j << " " << boxes[i].y << endl;
                    cout << boxes[i].sprite.getPosition().x << " " << boxes[i].sprite.getPosition().y << endl;


                    boxes[i].x--;


                    cout << boxes[i].x << " " << boxes[i].y << endl;
                    cout << mapo[boxes[i].y][boxes[i].x - j].sprite.getPosition().x << " " << mapo[boxes[i].y][boxes[i].x - j].sprite.getPosition().y << endl;
if(isThisInput(mapo,dir,i, color))
                        {
                            Object temp;
                            temp = background;
                            temp.sprite.setPosition(boxes[i].x * 64.0f, boxes[i].y * 64.0f);
                            mapo[boxes[i].y][boxes[i].x] = temp;
                            cout << "erasing..." << endl;
                            boxes.erase(boxes.begin() + i);
                            done = 0;
                            cout << "erased!" << endl;

                        }
                }
            else done--;
            break;
        }
        if (done <= 0) break;
    }
}

void moveBox(Object mapo[15][15], int dir, bool & loadMap)
{
    if(boxes.size() == 1)
    {
            boxesMusic.openFromFile("muz\\box1.wav");
            boxesMusic.setLoop(false);
            boxesMusic.play();
    }
    else if(boxes.size() > 1)
    {
            boxesMusic.openFromFile("muz\\box2.wav");
            boxesMusic.setLoop(false);
            boxesMusic.play();
    }
    bool endThis = false;


    for(int i = 0; i < boxes.size(); i++)
    {
        for(int notnot = 0; notnot < boxes.size(); notnot++)
        {
            if(mapo[boxes[notnot].y][boxes[notnot].x].box)
                {
                    cout << "moving box" << notnot << endl;
                    checkForBlock(mapo, dir, notnot, mapo[boxes[notnot].y][boxes[notnot].x].color);
                    checkForInput(mapo,dir,notnot, mapo[boxes[notnot].y][boxes[notnot].x].color);
                    checkForLose(mapo,dir,notnot, loadMap);
                }
        }
        if(endThis)
            break;


    }
    cout << "ended loop" << endl;



}

#endif // BOX_H_INCLUDED
