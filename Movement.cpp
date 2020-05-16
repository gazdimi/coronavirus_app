#include "Movement.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


Movement::Movement()
{
    //ctor
}

Movement::~Movement()
{
    //dtor
}

void Movement::random_time_duration(){                  //random time delay
    srand(time(0));
    int secs = (rand() % 60);
    int mins = (rand() % 60);
}

int Movement::destination(int *x, int *y, int side){    //simulation of movement to a destination
    int t = rand() % 4;                                 //random direction, 4 directions according to Random waypoint
    int s[4]= {3,4,5,6};                                //speed limits
    int speed = s[rand() % 4];                          //get random number from 0 to 3 and access above table to get random speed
    switch(t){
        case 0 :                                        //move right to a destination
            *x = *x + speed;
            if (*x > side){*x = side;}
            else if(*x < 1){*x = 1;}
            break;
        case 1:                                         //move left to a destination
            *x = *x - speed;
            if (*x > side){*x = side;}
            else if(*x < 1){*x = 1 ;}
            break;
        case 2:                                         //move up to a destination
            *y = *y + speed;
            if(*y > side){*y = side;}
            else if(*y < 1){*y = 1;}
            break;
        case 3:                                         //move down to a destination
            *y = *y - speed;
            if(*y > side){*y = side;}
            else if (*y < 1){*y=1;}
            break;
    }
}



