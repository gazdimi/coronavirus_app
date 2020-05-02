#include "Movement.h"
#include <iostream>
#include <cmath>
#include <ctime>

Movement::Movement()
{
    //ctor
}

Movement::~Movement()
{
    //dtor
}

void Movement::random_time_duration(){
    srand(time(0));
    int secs = (rand() % 60);
    int mins = (rand() % 60);
}
