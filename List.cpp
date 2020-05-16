#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>

using namespace std;

List::List()                                    //constructor
{
    head = NULL;                                //initialize head and tail pointers
    tail = NULL;
    day_to = new Node*[days];                   //initialize array with pointers storing memory address for each start of the day
    for (int i=0; i<days; i++){
        day_to[i] = NULL;
    }
}

List::~List()                                   //destructor
{
    delete head, tail, day_to, days;            //release memory resources
}

void List::Insert(int x, int y, int h, int m, int s){
    int total_secs = ((h * 60 ) + m) * 60 + s;  //total seconds of current time
    int previous_secs;                          //store time duration of previous node in seconds
    Node *temp = new Node;                      //create pointer of type Node and initialize it with Node instance
    temp -> x = x;                              //initialize all structure values
    temp -> y = y;                              //assign Node variables to values
    temp -> h = h;
    temp -> m = m;
    temp -> s = s;
    temp -> next = NULL;
    if (head==NULL){                            //case of empty list
        head = temp;                            //head equals tail
        tail = temp;
        temp = NULL;                            //prepare temp for next node (when it will be given)
        day_to[0] = head;                       //first memory address of first day will always be the head
    }else{                                      //case of one or more existing list nodes, previous tail will point to current node (temp)
        tail -> next = temp;                    //meaning pass current memory address of temp to the next pointer of tail node
        tail = temp;                            //assign tail to temp (last node), tail always points to last node
        if (total_secs - previous_secs < 0){    //if previous day ended
            for (int i=1; i<days; i++){
                if(day_to[i]==NULL){            //if any memory address has not been stored for current new day
                    day_to[i] = temp;           //pass the first memory address of current new day
                    break;                      //break in order to assign only the first memory address of day's first node
                }
            }
        }
    }
    previous_secs = total_secs;                 //at the end of current node's insert, assign to previous seconds current ones
}

void List::Output(){                            //display list's elements
    Node *temp = new Node;                      //start from head of the list
    temp = head;
    cout << "List elements: ";
    while(temp != NULL){                        //while there is another node connected
        cout << temp -> x << "," << temp -> y << " " << temp -> h << ":" << temp -> m << ":" << temp -> s << " | ";
        temp = temp -> next;                    //assign temp with next nodes's memory address
    }
    cout << endl;

    /*cout << "List elements by day: " << endl;
    Node *cemp = new Node;
    for (int i=0; i<days; i++){
        cout << "Day " << i + 1 << endl;
        cemp = day_to[i];
        temp = cemp;
        while(temp != day_to[i+1]){
            cout << temp -> x << "," << temp -> y << " " << temp -> h << ":" << temp -> m << ":" << temp -> s << " | ";
            temp = temp -> next;
        }
        cout << endl;
    }*/
}

int List::getRandom(int prev, int curr){
    int number;
    random_device myRandom;                     //create random_device object
    unsigned seed = myRandom();                 //generate a random seed
    default_random_engine myRandomEngine(seed); //initialize the random_engine with the seed
    if (prev > curr){
        uniform_int_distribution<int>  myDist(curr, prev); //initialize uniform_int_distribution to produce values between given range
        number = myDist(myRandomEngine);        //get a random number
    }else if(prev < curr){
        uniform_int_distribution<int>  myDist(prev, curr);
        number = myDist(myRandomEngine);
    }else{                                      //if prev==curr
        number = prev;
    }
    return number;
}

void List::Repair(int day){                     //if pair of nodes time difference is more than 30 seconds, create repaired node and add it between them
    Node *curr = new Node;                      //current node
    Node *previous = new Node;                  //previous node
    Node *repaired = new Node;                  //repaired node
    Node *next_day = new Node;                  //node's memory address of next day

    curr = day_to[day];                         //start with day's first node
    previous = curr;                            //initialize previous with current's node memory address
    next_day = NULL;
    if (days!=1 && day!=0 && day+1!=days){      //if user has not given only one day, and it's not the first day of total days and it is not the last
        next_day = day_to[day+1];               //then there is a next day, so assign to next_day the memory address of next day's first node
    }
    int rep_x, rep_y, rep_time, prev_secs, curr_secs;

    while (curr != NULL){                       //while there is another node to handle
        prev_secs = ((previous -> h * 60 ) + previous -> m) * 60 + previous -> s;   //calculate total seconds of previous node
        curr_secs = ((curr -> h * 60 ) + curr -> m) * 60 + curr -> s;               //calculate total seconds of current node
        if (curr_secs - prev_secs > 30){
            rep_x = getRandom(previous->x, curr->x);    //get random repaired x between range of previous x and current x
            rep_y = getRandom(previous->y, curr->y);    //get random repaired y between range of previous y and current y
            rep_time = getRandom(prev_secs, curr_secs); //get random repaired total seconds between range of previous total seconds and current total seconds

            repaired -> x = rep_x;                      //initialize all structure values of repaired node
            repaired -> y = rep_y;                      //assign Node variables to values
            repaired -> h = rep_time/3600;              //calculate hour, minutes, seconds of repaired total seconds
            repaired -> m = (rep_time%3600)/60;
            repaired -> s = rep_time%60;
            previous -> next = repaired;                //assign next pointer of previous node with the memory address of repaired node
            repaired -> next = curr;                    //assign next pointer of repaired node with the memory address of current node

        }
        previous = curr;                                //previous will become the current memory address
        curr = curr -> next;                            //pass memory address of next node to current
        if(curr==next_day){break;}                      //case when there is a next day, if next day's first node has been reached break loop
    }
}

