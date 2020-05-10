#include "List.h"
#include <iostream>
using namespace std;

List::List(int d)                               //constructor
{
    head = NULL;
    tail = NULL;
    days = d;
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

