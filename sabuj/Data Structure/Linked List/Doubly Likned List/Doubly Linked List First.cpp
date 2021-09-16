/**
   SABUJ KUMAR TAROFDAR....

      Doubly Linked List First.

      Insert_End(int x)
      Insert_Begin(int x)
      insert_nth(int x,int n)
      Delete_node(int Node_Position)
      print()
      Delete_in_End()
      Delete_In_Beginning()

**/

#include<stdio.h>
#include<bits/stdc++.h>
long long check = 0;

using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

node *head = NULL;

void Insert_End(int x)
{
    node *temp = new node();

    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;

        check++;

        return;
    }
    node *temp1 = head;

    while(temp1->next != NULL)
        temp1 = temp1->next;

    temp1->next = temp;
    temp->prev  = temp1;
    check++;
}
void Insert_Begin(int x)
{
    node *temp = new node();

    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        check++;

        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    check++;
}
void insert_nth(int x,int n)
{
    bool flag = true;

    node *temp1,*temp2,*temp = new node();

    if(head == NULL)
    {
       if(n == 1)
       {
           check++;
           head = temp;
       }
       else
       {
         cout<<"Sorry You Press Wrong Key Baby.."<<endl;
         delete(temp);
       }
       return;
    }
    if(n == 1)
    {
        temp->data = x;
        temp->prev = NULL;
        temp->next = NULL;

        temp->next = head;
        temp->next->prev = temp;
        head = temp;

       return;
    }

    temp->data =  x;
    temp->prev = NULL;
    temp->next = NULL;

    temp1 = head;

    for(int i = 0; i < n; i++)
    {
       if(temp1->next != NULL)
           temp1 = temp1->next;

       else if(i < n-1)
       {
           flag = false;
            break;
       }
       else
          break;
    }

    if(flag == false)
    {
        cout<<"\n\nOhho Baby Your Link Is Too Sort\n\n";

        delete(temp);

        return;
    }

    temp2 = temp1->next;

    temp->next = temp1->next;
    temp->prev = temp1;
    temp1->next = temp;
    temp2->prev = temp;
    check++;
}
void Delete_In_Beginning()
{
    check--;

    if(check < 0)
    {
        cout<<"\n\nYour List Is Empty Baby.\n\n";
        head = NULL;
        return;
    }
    if(head == NULL)
    {
        cout<<"\n\nYour List Is Already Empty Baby..\n\n";
        return;
    }
    node *temp;

    temp = head;

    head = temp->next;

    delete(temp);

}
void Delete_in_End()
{
    check--;

    if(check < 0)
    {
        cout<<"\n\nYour List Is Empty Baby.\n\n";
        head = NULL;
        return;
    }
    if(head == NULL)
    {
        cout<<"\n\nList Is Empty Baby..\n\n";
        return;
    }

    node *temp,*temp1;

    temp = head;

    while(temp->next != NULL)
        temp = temp->next;

   temp1 = temp->prev;

   temp1->next = NULL;

   delete(temp);

}
void Delete_node(int Node_Position)
{
    bool flag = true;

    check--;

    if(check < 0)
    {
        cout<<"\n\nYour List Is Empty Baby.\n\n";

        head = NULL;
        return;
    }
    if(Node_Position == 1)
    {
        node *temp3 = head;

        head = temp3->next;

        head->prev = NULL;

        delete(temp3);
        check--;
    }

    if(head == NULL)
    {
        cout<<"\n\nYou Have No Link Baby\n\n";
        return;
    }
    node *temp = head;

    for(int i = 0; i < Node_Position-1; i++)
    {
       if(temp->next != NULL)
           temp = temp->next;

       else if(i < Node_Position-1)
       {
           flag = false;
            break;
       }
    }

    if(flag == false)
    {
        cout<<"\n\nOhho Baby Your Link Is Too Sort..How Can I Remove Baby.. ??\n\n";
        return;
    }

    node *temp1,*temp2;

    temp1 = temp->prev;
    temp2 = temp->next;

    temp1->next = temp2;
    temp2->prev = temp1;

    delete(temp);
}
void print()
{
    node *temp = head;

    while(temp != NULL)
    {
       cout<<"Temp previous = "<<temp->prev<<", temp Next = "<<temp->next<<", Data  = "<<temp->data<<endl;
       temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    while(1)
    {
        int input,n,x;

        cout<<"If You Insert Value In The Beginning Press 1.\n";
        cout<<"If You Insert Value In The End Press 2.\n";
        cout<<"If You Insert Value In The N'th Position Press 3.\n";
        cout<<"If You Delete Value In The Beginning Press 4.\n";
        cout<<"If You Delete Value In The End Press 5.\n";
        cout<<"If You Delete Value In The N'th Position Press 6.\n";
        cout<<"If You Want Print Value 7.\n";
        cout<<"press 0 For Exit.\n";

        cin>>x;

        if(x == 0)
            break;

        else if(x == 1)
        {
            cout<<"\n\nEnter The Value... ";
            cin>>input;
            Insert_Begin(input);
        }
        else if(x == 2)
        {
            cout<<"\n\nEnter The Value... ";
            cin>>input;

            Insert_End(input);
        }
        else if(x == 3)
        {
            cout<<"\n\nEnter The Value And Position..  ";
            cin>>input>>n;
            insert_nth(input,(n-2));
        }
        else  if(x == 4)
        {
            Delete_In_Beginning();
        }
        else if(x == 5)
        {
            Delete_in_End();
        }
        else if(x == 6)
        {
            cin>>n;
            Delete_node(--n);
        }
        else if(x == 7)
        {
            printf("\n");
            print();
        }
        else
        {
            cout<<"\n\nWrong Key Baby\n\n";
        }
        cout<<endl;
    }
    return 0;
}
