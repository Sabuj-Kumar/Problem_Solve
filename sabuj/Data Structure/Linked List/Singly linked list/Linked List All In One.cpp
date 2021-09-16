/**
          UNIVERSITY OF ASIA PECIFIC

          ** SABUJ KUMAR TAROFDFAR **

                LINKED LIST IMPLEMENTATION CODE.CPP
**/

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int Data;

    Node *Adress;
};

Node *Head = NULL;
Node *Tail = NULL;

Node *Create_Node(int Value)
{
    Node *node = new Node();

    node -> Data = Value;

    node -> Adress = NULL;

    return node;
}

void Begin_Insert(int Value)
{
    Node *node = Create_Node(Value);

    if(Head == NULL)
    {
        Head = node;

        Tail = node;

        cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED FIRST.\n\n\n";
        return;
    }

    node -> Adress = Head;

    Head = node;

    cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED FIRST.\n\n\n";
}
void End_Insert(int Value)
{
    Node *node = Create_Node(Value);

    if(Head == NULL)
    {
        Head = node;

        Tail = node;

        cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED FIRST.\n\n\n";

        return;
    }

    Tail -> Adress = node;

    Tail = node;

    cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED LAST.\n\n\n";
}
void Any_Position_Insert(int Value,int Position)
{
    Node *node = Create_Node(Value);

    int Length = 1;


    if(Position == 1)
    {
        node -> Adress = Head;

        Head = node;

        cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED "<< Position <<" POSITION.\n\n\n";

        return;
    }

    Node *node1 = Head;

    while(node1 -> Adress != NULL)
    {
        node1 = node1 -> Adress;
        Length++;
    }

    if(Length+1 < Position)
    {
        cout << "\n\n\tLIST IS SORT.\n\n\n";
        return;
    }

    node1 = Head;

    for(int i = 1; i < Position-1; i++)
        node1 = node1 -> Adress;


    node -> Adress = node1 -> Adress;

    node1 -> Adress = node;

    cout <<"\n\n\t"<< node -> Data << "\tIS INSERTED "<< Position <<" POSITION.\n\n\n";
}
void Delete_Begin()
{
    if(Head == NULL)
    {
        cout << "\n\n\tLIST IS SORT.\n\n\n";
        return;
    }

    Node *node = Head;

    Head = Head -> Adress;

    cout <<"\n\n\t"<< node -> Data << "\tIS DELETED FROM FIRST.\n\n\n";

    delete(node);
}
void Delete_End()
{
    Node *node = Head;
    Node *Delete_Node;

    if(Head == NULL)
    {
         cout << "\n\n\tLIST IS SORT.\n\n\n";

        return;
    }

    if(node -> Adress != NULL)
    {
        while(node -> Adress -> Adress != NULL)
            node = node -> Adress;

        Delete_Node = node -> Adress;

        node -> Adress = NULL;

        Tail = node;
    }
    else
    {
        Delete_Node = node;

        Head = NULL;
    }

    cout <<"\n\n\t"<< Delete_Node -> Data << "\tIS DELETED FROM LAST.\n\n\n";

    delete(Delete_Node);
}
void Delete_Any_Position(int Position)
{
    Node *node = Head;
    Node *Delete_Node;

    int Length = 0;

    if(Head == NULL)
    {
         cout << "\n\n\tLIST IS SORT.\n\n\n";

        return;
    }

    if(Position == 1)
    {
        Head = Head -> Adress;

        cout <<"\n\n\t"<< node -> Data << "\tIS DELETED FROM " << Position << " POSITION.\n\n\n";

        delete(node);

        return;
    }

    while(node ->Adress != NULL)
    {
        node = node -> Adress;
        Length++;
    }

    if(Length+1 < Position)
    {
        cout << "\n\n\tLIST IS SORT.\n\n\n";
        return;
    }
    node = Head;

    for(int i = 1; i < Position-1; i++)
        node = node -> Adress;

    Delete_Node = node -> Adress;

    if(Delete_Node == Tail)
    {
         Tail = node;

         Tail -> Adress = NULL;
    }
    node -> Adress = Delete_Node -> Adress;

    cout <<"\n\n\t"<< Delete_Node -> Data << "\tIS DELETED FROM " << Position << " POSITION.\n\n\n";

    delete(Delete_Node);
}
void Print()
{
    Node *node = Head;

    if(Head == NULL)
    {
        cout << "\n\n\tLIST IS EMPTY.\n\n\n";

        return;
    }

    cout << "\n\n\tLIST IS : \n\n";

    while(node != NULL)
    {
        cout << "\t\tDATA  <->  " << node -> Data << endl;
        node = node -> Adress;
    }

    cout << "\n\n";
}
int main()
{
    cout <<"\n\tLETS  START.\n\n\n";

    while(1)
    {
        int key,Value,Position;

        cout << "\t\tFOR INSERT FIRST PRESS -> (1).\n\n";
        cout << "\t\tFOR INSERT LAST PRESS -> (2).\n\n";
        cout << "\t\tFOR INSERT ANY POSITION PRESS -> (3).\n\n";
        cout << "\t\tFOR DELETED FIRST PRESS -> (4).\n\n";
        cout << "\t\tFOR DELETED LAST PRESS -> (5).\n\n";
        cout << "\t\tFOR DETETED ANY POSITION PRESS -> (6).\n\n";
        cout << "\t\tFOR PRINT PRESS -> (7)\n\n";
        cout << "\t\tFOR EXIT PRESS -> (0)\n\n";
        cout << "\tPRESS  KEY  :  ";

        cin >> key;

        if(key == 1)
        {
            cout << "\n\n\tENTER THE DATA :  ";

            cin >> Value;

            Begin_Insert(Value);
        }
        else if(key == 2)
        {
            cout << "\n\n\tENTER THE DATA :  ";

            cin >> Value;

           End_Insert(Value);
        }
        else if(key == 3)
        {
            cout << "\n\n\tENTER THE DATA :  ";
            cin >> Value;

            cout << "\n\n\tENTER THE POSITION :  ";
            cin >> Position;

            Any_Position_Insert(Value,Position--);
        }
        else if(key == 4)
            Delete_Begin();

        else if(key == 5)
            Delete_End();

        else if(key == 6)
        {
            cout << "\n\n\tENTER THE POSITION :  ";

            cin >> Position;

            Delete_Any_Position(Position--);
        }

        else if(key == 7)
            Print();

        else if(key == 0)
            break;

        else
            cout << "\n\tWRONG  KEY  BRO.\n\n";
    }

    cout << "\n\n\n\t\t\tTHANKS\n\n\n";

    return 0;
}
