#include<stdio.h>
#include<iostream>

using namespace std;

struct node
{
    int data;

    node *next;
};
node *head = NULL;

void print()
{
    node *temp = head;

    cout<<"List Is :"<<endl;

    while(temp != NULL)
    {
        cout<<"temp = "<<temp<<", data = "<<temp->data<<", next = "<<temp->next<<endl;
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int input,i,n;

    cout<<"Enter The N'th Value. "<<endl;
    cin>>n;
    cout<<"Enter The Element's. "<<endl;
    cin>>input;

    node *temp;

    temp =  new node;
    temp->data = input;
    temp->next = NULL;
    head = temp;
    print();
    --n;

    for(i = 0; i < n; i++)
    {
       cout<<"Enter The Element's. "<<endl;
       cin>>input;
       temp =  new node;
       temp->data = input;
       temp->next = head;
       head = temp;
       print();
    }
    return 0;
}
