#include "Movement.h"
#include <iostream>
#include <cmath>
#include <ctime>
//#include <stdio.h> #include <stdlib.h>

using namespace std;

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
    cout << "Movement " << mins << ":" << secs << endl;
}

int Movement::destination(int x,int y,int side){

    srand(time(0));
    int r = (rand() % side) ;
    int c= (rand() % side) ;

    int t[4]= {3,4,5,6}; //speed

    int distance_x=abs(x-r);
    int distance_y=abs(y-c);  //absolute value

    int f_d= distance_x + distance_y;
    int speed,rem;
    for(int i=0; i<4; i++){

            if(f_d % t[i]==0){
                speed=t[i];
                rem=0;
                }else if (f_d % t[i]==1){
                    speed=t[i];
                    rem=1;}
                else if (f_d % t[i]==2){
                        speed=t[i];
                        rem=2;
                }
            }
    cout << "Speed is: " << speed << endl << "Remaining blocks: " << rem << endl;

/* int surface[side][side];

    if(x<r && y<c){

     for(i=x; i<r; i++){
        surface[i][y]=1;
     }
        for(j=y; j<c; j++){
        surface[r][j]=1;
     }
    }
     else if(x<r && y>c){
            for(i=x; i<r; i++){
        surface[i][y]=1;
     }
        for(j=y;j>c; j--){
            surface[r][j]=1;
        }
     }
     else if(x>r && y<c){
        for(i=x; i>r; i--){
            surface[i][y]=1;
        }
        for(i=y;i<c;i++){
            surface[r][i]=1;
            }
     }else{
     for(i=x; i>r; i--){
            surface[i][y]=1;
        }
        for(i=y;i>c; i--){
            surface[r][i]=1;
        }

     } */
}
