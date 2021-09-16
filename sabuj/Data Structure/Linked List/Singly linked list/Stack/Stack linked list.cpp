#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void push(int input)
{
    node *temp;

    temp = new node();

    temp->data = input;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    temp -> next = head;
    head = temp;
}
void pop()
{
    if(head == NULL)
        cout<< "\nNode does not exist ...\n\n";

    else
    {
        node *Node = head;

        head = head->next;

        delete(Node);
    }
}
void print()
{
    if(head == NULL)
      cout<< "\nThere Is No Value.\n\n";

    else
    {
        node *temp = head;

        cout<< "List Is: \n\n";

        while(temp != NULL)
        {
            cout<< "Data: "<<temp->data<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    int input,n;

    while(1)
    {
        cout<< "If You Want Push Value Press 1.\n";
        cout<< "If You Want Pop Value Press 2.\n";
        cout<< "If You Want Print Value Press 3.\n";
        cout<< "If You Want Exit Press 0.\n\n";
        cout<< "Press Key :  ";
        cin>>n;

        if(n == 1)
        {
            cout<< "Enter The Value  =  ";
            cin>> input;

            push(input);
        }
        else if(n == 2)
            pop();

        else if(n == 3)
            print();

        else if(n == 0)
            break;

        else
            cout<< "\nYou press wrong key\n\n";
    }
    return 0;
}
