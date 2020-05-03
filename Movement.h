#ifndef MOVEMENT_H
#define MOVEMENT_H


class Movement
{
    public:
        Movement();
        virtual ~Movement();
        void random_time_duration();
        int destination(int x,int y,int side);
    protected:

    private:
};

#endif // MOVEMENT_H
