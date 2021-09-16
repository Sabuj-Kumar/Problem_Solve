/**
   1st:

     insert value in last position linked list.

**/

/**

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

    cout<<"list Is: "<<endl;

    while(temp != NULL)
    {
       cout<<"Temp = "<<temp<<", Data = "<<temp->data<<", Next = "<<temp->next<<endl;
       temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int input,i,n;

    node *temp,*temp1;

    cout<<"Enter The N'th Value : ";
    cin>>n;
    cout<<"Enter The Element's : ";
    cin>>input;

    temp = new node;
    temp->data = input;
    temp->next = NULL;
    head = temp;

    temp1 = head;
    print();
    n--;

    for(i = 0; i < n; i++)
    {
        cout<<"Enter The Element's : ";
        cin>>input;

        temp = new node;
        temp->data = input;
        temp->next = NULL;
        temp1 = head;

        while(temp1->next != NULL)
           temp1 = temp1->next;

        temp1->next = temp;
        print();
    }
    return 0;
}
**/


/**
  2nd:

    Insert Element's In First position.
**/
/**

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

    cout<<"list Is: "<<endl;

    while(temp != NULL)
    {
       cout<<"Temp = "<<temp<<", Data = "<<temp->data<<", Next = "<<temp->next<<endl;
       temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    int input,i,n;

    node *temp;

    cout<<"Enter The N'th Value:  ";
    cin>>n;
    cout<<"Enter The Element's:  ";
    cin>>input;

    temp = new node;
    temp->data = input;
    temp->next = NULL;
    head = temp;
    print();
    n--;

    for(i = 0; i < n; i++)
    {
        cout<<"Enter The Element's:  ";
        cin>>input;

        temp = new node;
        temp->data = input;
        temp->next = head;
        head = temp;
        print();
    }
    return 0;
}
**/

/**
   3rd:

    Insert Any  Position Of A Liked List

**/
/**

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

    cout<<"list Is: "<<endl;

    while(temp != NULL)
    {
       cout<<"Temp = "<<temp<<", Data = "<<temp->data<<", Next = "<<temp->next<<endl;
       temp = temp->next;
    }
    cout<<endl;
}
void insert_elements_in_position(int value,int pos)
{
   int i;
   node *temp1,*temp2;

   temp1 = new node;
   temp1->data = value;
   temp1->next = NULL;

   if(pos == 1)
   {
       temp1->next = head;
       head = temp1;
       return;
   }
   else
   {
      temp2 = head;

      for(i = 0; i <= (pos-2); i++)
         temp2 = temp2->next;

      temp1->next = temp2->next;
      temp2->next = temp1;
   }
}
int main()
{
    int input,i,n,pos;

    cout<<"Enter The N'th Value:  ";
    cin>>n;
    cout<<"Enter The Element's And Position:  ";
    cin>>input>>pos;

    node *temp;
    temp = new node;
    temp->data = input;
    temp->next = NULL;
    head = temp;
    print();
    --n;

    for(i = 0; i < n; i++)
    {
        cout<<"Enter The Element's And Position:  ";
        cin>>input>>pos;

        insert_elements_in_position(input,pos);
        print();
    }
    return 0;
}
**/

