#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>
#include "Movement.h"
#include "List.h"

using namespace std;

void gps(Movement *m, List *l, int side, int days){
    int x = (rand() % side);                            //initialize the people in random locations inside the surface
    int y = (rand() % side);
    for (int d=0; d<days; d++){
        for (int hour=0; hour<24; hour++){              //day
            for (int minu=0; minu<60; minu++){          //hour
                int counter = 0;
                for (int sec=0; sec<60; sec++){         //minute
                    int stop_gps = rand() % 2;
                    int delay = (rand() % 60);
                    m -> destination(&x, &y, side);
                    if(counter == 30){
                        if(stop_gps==1){
                            l -> Insert(x,y,hour,minu,sec);
                        }else{
                            int tot = sec + delay;
                            sec += delay;
                            if (sec>=60){
                                sec = tot - 60;
                                minu++;
                                if(minu>59){
                                    hour++;
                                    minu--;
                                }
                                if(hour>23){
                                    d++;
                                    hour--;
                                }
                            }
                            counter = sec;
                            if(d>=days){break;}
                        }
                        counter = 0;
                    }
                    counter++;
                }
            }
        }
    }
}

bool menu(){
    bool flag = false;                  //check if valid menu option has been given
    while(!flag){
        char option;
        cout << "Coronavirus app - Main menu\nSelect an option from below:\n1. Start GPS tracking";
        cout << "\n2. Exit\nEnter option's number: ";
        cin >> option;
        switch(option){
        case '1':                       //start simulation of movement (GPS tracking)
            flag = true;
            return flag;
            break;
        case '2':                       //exit option
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

int List::days;
int input_days() {

    cout << "\nSelect number of days from 1 to 5:" << endl;
    //int d;
    while (!(cin >> List::days && List::days >= 1 && List::days <= 5)) {          //check input, while it's invalid
            cin.clear();                                            //clear input buffer from user's input
            cin.ignore(1000, '\n');                                 //ignore last 1000 input characters until new line
            cout << "Invalid input, try again.\n" << endl;
    }
    return List::days;
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

            int days = input_days();

            srand(time(0));                                             //pseudo-random number generator using time as an unpredictable seed
            int sick = (rand() % people) + 1;                           //random number of infected from 1 to people
            int grid =  people * 16;                                    //personal grid will be 4x4 = 16 blocks totally, for checking radius = 2
            int side = round(sqrt(grid));                               //side of the grid

            Movement m_infected[sick];
            List infected[sick];
            for(int i=0; i<sick; i++){
                gps(&m_infected[i], &infected[i], side, days);
            }
            //infected[0].Output();

            for(int i=0; i<1; i++){ //sick, only 1 person gia eukolia twra
                for(int j=0; j<days; j++){
                    infected[i].Repair(j);
                }
            }

            Movement m_healthy[people - sick];
            List healthy[people - sick];
            for(int i=0; i<people - sick; i++){
                gps(&m_healthy[i], &healthy[i], side, days);
            }
            //healthhealthy[0].Output();


        } catch(...){  cout << "Error";}
    }
}


