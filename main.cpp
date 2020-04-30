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

        srand(time(0));                     // Use current time as seed for random generator
        int sick = (rand() % people) + 1;

        int grid =  people * 16;
        int side = round(sqrt(grid));
        int surface[side][side];

        for (int i=0; i<side; i++){
            for (int j=0; j<side; j++){
                surface[i][j] = 0;
            }
        }

        for (int i=0; i<people; i++){
            int x = (rand() % side); //+ 1
            int y = (rand() % side);
            if(surface[x][y]!=1) { surface[x][y] = 1;}
        }



    } catch(...){

    }

}
