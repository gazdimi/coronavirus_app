#ifndef LIST_H
#define LIST_H

struct Node{
    int x, y, h, m, s;  //data of the node
    Node *next;         //pointer that links to the next memory address
};

class List
{
    public:
        List(int d);
        ~List();
        Node *head;     //stores the memory address of the first node
        Node *tail;     //stores the memory address of the last node
        Node** day_to;  //pointer of type node, that will store memory address of node representing the beginning of the day
        int days;
        void Insert(int x, int y, int h, int m, int s);
        void Output();
    protected:

    private:
};

#endif // LIST_H
