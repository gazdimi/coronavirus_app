#include "List.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <random>

using namespace std;

List::List()                               //constructor int d
{
    head = NULL;
    tail = NULL;
    day_to = new Node*[days];
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
        day_to[0] = head;
    }else{                                      //case of one or more existing list nodes, previous tail will point to current node (temp)
        tail -> next = temp;                    //meaning pass current memory address of temp to the next pointer of tail node
        tail = temp;                            //assign tail to temp (last node), tail always points to last node
        if (total_secs - previous_secs < 0){
            for (int i=1; i<days; i++){
                if(day_to[i]==NULL){
                    day_to[i] = temp;
                    break;
                }
            }
        }
    }
    previous_secs = total_secs;
}

void List::Output(){
    Node *temp = new Node;
    temp = head;
    cout << "List elements: ";
    while(temp != NULL){
        cout << temp -> x << "," << temp -> y << " " << temp -> h << ":" << temp -> m << ":" << temp -> s << " | ";
        temp = temp -> next;
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
    random_device myRandom;
    unsigned seed = myRandom();
    default_random_engine myRandomEngine(seed);
    if (prev > curr){
        uniform_int_distribution<int>  myDist(curr, prev);
        number = myDist(myRandomEngine);
    }else if(prev < curr){
        uniform_int_distribution<int>  myDist(prev, curr);
        number = myDist(myRandomEngine);
    }else{
        number = prev;
    }
    return number;
}

void List::Repair(int day){
    Node *curr = new Node;                  //current node
    Node *previous = new Node;              //previous node
    Node *repaired = new Node;
    //Node *next_day = new Node;              //node's memory address of next day

    curr = day_to[day];
    previous = curr;
    //next_day = day_to[day+1];
    int rep_x, rep_y, rep_time, prev_secs, curr_secs;

    if (days == 1){                         //only one available day
        while (curr != NULL){
            prev_secs = ((previous -> h * 60 ) + previous -> m) * 60 + previous -> s;
            curr_secs = ((curr -> h * 60 ) + curr -> m) * 60 + curr -> s;
            if (curr_secs - prev_secs > 30){
                rep_x = getRandom(previous->x, curr->x);
                rep_y = getRandom(previous->y, curr->y);
                rep_time = getRandom(prev_secs, curr_secs);

                repaired -> x = rep_x;                              //initialize all structure values of repaired node
                repaired -> y = rep_y;                              //assign Node variables to values
                repaired -> h = rep_time/3600;
                repaired -> m = (rep_time%3600)/60;
                repaired -> s = rep_time%60;
                previous -> next = repaired;
                repaired -> next = curr;

                cout << "previous: " << previous -> x << "," << previous -> y << " " << previous -> h << ":" << previous -> m << ":" << previous -> s << " ";
                cout << "repaired: " << repaired -> x << "," << repaired -> y << " " << repaired -> h << ":" << repaired -> m << ":" << repaired -> s << " ";
                cout << "current: " << curr -> x << "," << curr -> y << " " << curr -> h << ":" << curr -> m << ":" << curr -> s << endl;
                break;
            }
            previous = curr;
            curr = curr -> next;
        }
    }
}

