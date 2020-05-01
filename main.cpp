#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{   //r=2, private_grid = 4x4 = 16
    try{
        cout << "Select number of people from 5 to 50:" << endl;
        int people;
        cin >> people;

        srand(time(0));                     //use current time as seed for random generator
        int sick = (rand() % people) + 1;   //random number infected

        int grid =  people * 16;
        int side = round(sqrt(grid));       //side of the grid
        int surface[side][side];

        for (int i=0; i<side; i++){
            for (int j=0; j<side; j++){     //initialize the surface with zeros
                surface[i][j] = 0;
            }
        }

        for (int i=0; i<people; i++){
            int x = (rand() % side);        //initialize the people in random locations inside the surface
            int y = (rand() % side);
            if(surface[x][y]!=1) { surface[x][y] = 1;}
        }
        for (int hour=0; hour<24; hour++){      //day
            for (int min=0; min<60; min++){     //hour
                for (int sec=0; sec<60; sec++){ //minute
                    cout << "time " << hour <<":"<<min<<":"<<sec << endl;
                }
            }
        }
    } catch(...){

    }

}
