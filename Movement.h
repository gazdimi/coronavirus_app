#ifndef MOVEMENT_H
#define MOVEMENT_H


class Movement
{
    public:
        Movement();                                 //default constructor
        ~Movement();                                //default destructor
        void random_time_duration();                //calculate random time delay for staying in a location
        int destination(int *x, int *y, int side);  //function for simulating person's movement
};

#endif // MOVEMENT_H
