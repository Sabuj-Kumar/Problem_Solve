#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;

    node *next;
};

node *head = NULL;
node *tail = NULL;

node *creat_node(int value)
{
    node *temp = new node();

    temp -> data = value;
    temp -> next = NULL;

    return temp;
}
void push(int value)
{
    node *temp = creat_node(value);

    if(head == NULL && tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail -> next = temp;

    tail = temp;
}
void pop()
{
    if(head == NULL && tail == NULL)
    {
        cout << "\n\n       OPPS! There Is No Data\n";
        return;
    }
    if(head == tail)
    {
        cout << "\n\n       " << head -> data << "  IS  DELETED.\n\n";
        head = NULL;
        tail = NULL;
        return;
    }

    node *temp = head;

    cout << "\n\n       " << head -> data << "  IS  DELETED.\n\n";

    head = head -> next;

    delete(temp);
}
void print()
{
    if(head == NULL && tail == NULL)
    {
        cout << "\n\n       OPPS! There Is No Data\n";
        return;
    }

    node *temp = head;

    cout << "\n\n     DATA LIST : \n";

    while(temp != NULL)
    {
        cout << "\n         Data = "<< temp -> data << endl;
        temp = temp -> next;
    }
    cout << endl;
}
int main()
{
    cout << "\n\n       Let's Star Queue.\n\n";

    cout << "                    \"\"\"\"\" QUEUE \"\"\"\"\"\n\n";

    while(1)
    {
        int key;

        cout << "\n\n                 If You Insert Data Press Key 1.";
        cout << "\n                 If You Delete Data Press Key 2.";
        cout << "\n                 If You Want To See Data Press Key 3.";
        cout << "\n                 For Exit Press Key 0.\n";
        cout << "\n                 Press Key Please :  ";

        cin >> key;

        if(key == 0)
            break;

        else if(key == 1)
        {
            int value;

            cout << "\n\n       Please Insert Data :  ";
            cin >> value;

            push( value );
        }
        else if(key == 2)
            pop();

        else if(key == 3)
        {
            print();
        }

        else
            cout << "\n\n       OHHO!  You Press Wrong Key...\n\n";
    }

    cout << "\n\n                 \"\"\"\"  THANKS  \"\"\"\"\n\n\n";

    return 0;
}
