#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include "Movement.h"
#include "List.h"

using namespace std;


void gps(Movement *m, List *l, int side){
    int x = (rand() % side);                                //initialize the people in random locations inside the surface
    int y = (rand() % side);
    for (int hour=0; hour<1; hour++){                       //day
        for (int min=0; min<10; min++){                      //hour
            int counter = 0;
            for (int sec=0; sec<60; sec++){                 //minute
                m -> destination(&x, &y, side);
                if(counter == 30){
                    l -> Insert(x,y,hour,min,sec);
                    counter = 0;
                }
                counter++;
            }
        }
    }
}

bool menu(){
    bool flag = false;                  //check if valid menu option has been given
    while(!flag){
        char option;
        cout << "Coronavirus app - Main menu\nSelect an option from below:\n1. Start GPS tracking";
        cout << "\n2. Find most crowded places\n3. Exit\nEnter option's number: ";
        cin >> option;
        switch(option){
        case '1':                       //start simulation of movement (GPS tracking)
            flag = true;
            return flag;
            break;
        case '2':                       //show to administrator info about most crowded places
            flag = true;
            cout << option;
            break;
        case '3':                               //exit option
            flag = true;
            cout << "Bye!!";
            exit(0);                            //terminate program
            break;
        default:
            cout << "Invalid input, try again.\n" << endl;
            break;
        }
    }
}

int main()  //r=2, private_grid = 4x4 = 16
{
    bool start = menu();
    if (start){
        try{
            cout << "\nSelect number of people from 5 to 50:" << endl;
            int people;
            while (!(cin >> people && people >= 5 && people <= 50)) {   //check input, while it's invalid
                cin.clear();                                            //clear input buffer from user's input
                cin.ignore(1000, '\n');                                 //ignore last 1000 input characters until new line
                cout << "Invalid input, try again.\n" << endl;
            }
            srand(time(0));                                             //pseudo-random number generator using time as an unpredictable seed
            int sick = (rand() % people) + 1;                           //random number of infected from 1 to people
            int grid =  people * 16;                                    //personal grid will be 4x4 = 16 blocks totally, for checking radius = 2
            int side = round(sqrt(grid));                               //side of the grid
            int surface[side][side];
            for (int i=0; i<side; i++){
                for (int j=0; j<side; j++){                             //initialize the surface with zeros
                    surface[i][j] = 0;
                }
            }
            /*cout << "Sicks: " << sick << endl;
            for(int i=1; i<=sick; i++){
                List s_i;
                Movement ms_i;
                gps(&ms_i, &s_i, side);
                cout<< "Infected person: " << i+1<< endl;
                s_i.Output();
                cout<< endl;
            }*/
            Movement a;
            List b;
            gps(&a,&b,side);
            cout << "Outside gps b:" << &b << endl;
            b.Output();
            cout << endl;
            Movement c;
            List d;
            gps(&c,&d,side);
            cout << "Outside gps d:" << &d << endl;
            d.Output();

        } catch(...){  cout << "Error";}
    }
}


