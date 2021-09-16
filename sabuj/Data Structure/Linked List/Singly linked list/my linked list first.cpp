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

void print()
{
    node *output = head;

    cout<<"List Is : "<<endl;

    while(output != NULL)
    {
       cout<<output->data<<" ";
       output = output->next;
    }
    cout<<endl;
}
node *create_node(int value,node *next)
{
    node *new_node = new node;

    if(new_node == NULL)
    {
        cout<<"Error. Not Create Node.\n"<<endl;
        exit(1);
    }

    new_node->data = value;
    new_node->next = next;

    return new_node;
}

node *pre_add(int data,node *head)
{
   node *new_node = create_node(data,head);

   return new_node;
}

int main()
{
    node *n,*n1,*n2;
    n = create_node(10,NULL);
    head = n;
    head = pre_add(30,head);

    n1 = head;
    cout<<"First Data = "<<n1->data<<endl;
    n2 = n1->next;
    cout<<"Second Data = "<<n2->data<<endl;

    return 0;
}
