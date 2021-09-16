#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void push(int input)
{
    node *temp,*temp1 = head;

    temp = new node();

    temp->data = input;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    while(temp1->next != NULL)
        temp1 = temp1->next;

    temp1->next = temp;
}
void pop()
{
    node *temp = head,*temp1;

    if(head == NULL)
    {
        cout<<"\nList Is Empty.\n"<<endl;
        return;
    }
    if(temp->next == NULL)
    {
         head = NULL;
         return;
    }

    temp1 = temp->next;
    head = temp1;

    delete(temp);
}
void print()
{
    node *temp = head;

    if(temp == NULL)
    {
        cout<<"\nList Is Empty.\n"<<endl;
        return;
    }

    cout<<"The List Is: \n"<<endl;

    while(temp != NULL)
    {
        cout<<"temp = "<<temp<<" data = "<<temp->data<<" next = "<<temp->next<<endl;
        temp = temp->next;
    }
    cout<<endl;

}

int main()
{
    int input,search;

    while(1)
    {
        cout<<"If You Want To Push Value Press 1."<<endl;
        cout<<"If You Want To Pop Value Press 2."<<endl;
        cout<<"If You Want To Print Press 3."<<endl;
        cin>>search;

        if(search == 1)
        {
            cout<<"Enter The Value.\n";
            cin>>input;

            push(input);
        }
        else if(search == 2)
            pop();

        else if(search == 3)
            print();
    }
    return 0;
}
