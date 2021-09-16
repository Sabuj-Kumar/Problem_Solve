#include<stdio.h>
#include<iostream>

using namespace std;

struct node
{
    int data;

    node *next;
};

node *head = NULL;
node *tail = new node;

void push_value(int value)
{
    node *temp,*temp1;

    if(head == NULL)
    {
        temp->data = value;
        temp->next = NULL;
        head = temp;
        return;
    }
    temp = head;

    while(temp != NULL)
    {
        temp = temp->next;
    }
    temp->data = value;
    temp->next = tail;
    temp1 = head;

    while(temp1 != NULL)
    {
        cout<<temp1->data<<" ";
        temp1 = temp1->next;
    }
}

void pop_value(int index)
{
    int i = 0;

    node *temp = head;

    if(head == NULL)
    {
       printf("List Is Empty.\n");
       return;
    }

    for(int j = 0; j < index-2; j++)
    {
        temp = temp->next;
    }
    printf("The Delete Value Is : ");
    cout<<temp->data<<endl;

    temp->next = tail;
}
void print()
{
    node *temp = head;

    if(head == NULL)
    {
        cout<<"List Is Empty."<<endl;
    }
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int input,press;
    node *temp;

    while(1)
    {
        int index = 0;

        cout<<"Enter The Choice :"<<endl;
        cout<<"Press 1 For Push:"<<endl;
        cout<<"Press 2 For Pop:"<<endl;
        cout<<"Press 3 For Print:"<<endl;
        cin>>press;

        if(press == 1)
        {
            cout<<"Enter The Value:  ";
            cin>>input;
            push_value(input);
        }
        else if(press == 2)
        {
            if(head != NULL)
            {
                node *temp = head;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                    index++;
                }
                pop_value(index);
            }
            else
            {
                cout<<"List Is Empty."<<endl;
            }
        }
        else if(press == 3)
        {
            print();
        }
    }
    return 0;
}
