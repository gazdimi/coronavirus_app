#ifndef LIST_H
#define LIST_H

struct Node{
    int x, y, h, m, s;              //data of the node
    Node *next;                     //pointer that links to the next memory address
};

class List
{
    public:
        List();                     //default constructor
        ~List();                    //default deconstructor
        static int days;            //user's input days
        friend int input_days();    //class' friend function for initializing days
        void Insert(int x, int y, int h, int m, int s); //insert node to list
        void Output();              //display list elements
        void Repair(int day);       //repair by day
        int getRandom(int prev, int curr);  //get random numbers, to create repaired  nodes

    private:
        Node *head;                 //stores the memory address of the first node
        Node *tail;                 //stores the memory address of the last node
        Node** day_to;              //pointer of type node, that will store memory address of node representing the beginning of the day
};

#endif // LIST_H
