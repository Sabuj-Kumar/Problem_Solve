#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};
node *head = NULL;

void insert_nth_position(int n,int pos)
{
     int i;

     node *temp,*temp1;
     temp = new node;
     temp->data = n;
     temp->next = NULL;

     if(pos == 1)
     {
         temp->next = head;
         head = temp;
         return;
     }
     temp1 = head;

     for(i = 0; i < (pos-2); i++)
        temp1 = temp1->next;

     temp->next = temp1->next;
     temp1->next = temp;
}
void print()
{
    node *temp = head;
    cout<<"List Is : "<<endl;

    while(temp != NULL)
    {
       cout<<"Temp = "<<temp<<", data = "<<temp->data<<", next = "<<temp->next<<endl;
       temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    int input,i,n,pos;

    cout<<"Enter The N'th Value.  ";
    cin>>n;

    for(i = 0; i < n; i++)
    {
        cout<<"Enter The Elements  And Position.  ";
        cin>>input>>pos;

        insert_nth_position(input,pos);
        print();
    }
    return 0;
}
