#include "List.h"
#include <iostream>
using namespace std;

List::List()                                    //constructor
{
    head = NULL;
    tail = NULL;
    temp_day = NULL;
}

List::~List()                                   //destructor
{
    delete head, tail, temp_day;                //release memory resources
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
    temp -> day_to = NULL;
    if (head==NULL){                            //case of empty list
        head = temp;                            //head equals tail
        tail = temp;
        temp = NULL;                            //prepare temp for next node (when it will be given)
        temp_day = head;
        //cout << "1st: " << temp_day << endl;
    }else{                                      //case of one or more existing list nodes, previous tail will point to current node (temp)
        tail -> next = temp;                    //meaning pass current memory address of temp to the next pointer of tail node
        tail = temp;                            //assign tail to temp (last node), tail always points to last node
        if ((86399 - total_secs <= 0) || (total_secs - previous_secs < 0)){
            temp -> day_to = temp_day;
            temp_day = NULL;
            temp_day = temp;
            //cout << "2nd: " << temp_day << endl;
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
}

