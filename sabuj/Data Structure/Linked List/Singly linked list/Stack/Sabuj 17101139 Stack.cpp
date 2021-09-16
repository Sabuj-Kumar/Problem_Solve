#include<bits/stdc++.h>

int Position = 0;

using namespace std;

struct node
{
    int data;

    node *next;
};

node *head = NULL;

node *Node(int value)
{
    node *temp;

    temp  = new node();

    temp -> data = value;
    temp -> next = NULL;

    return temp;
}

void push(int value)
{
    Position++;

    node *temp;

    temp = Node(value);

    if(head == NULL)
    {
         head =  temp;
         return;
    }
    temp -> next = head;

    head = temp;
}

void pop()
{
    node *temp;

    temp = head;

    if(head == NULL)
    {
        cout<<"\n\n\tOHH0!  THERE  IS  NO  VALUE.\n\n\n";
        return;
    }

    head = temp -> next;

    cout<<"\n\n\t"<<temp->data<<" IS DELETED.\n\n";

    delete(temp);

    Position--;
}

void print()
{
    int index = Position;

    node *temp = head;

    if(head  == NULL)
    {
        cout<<"\tOHH0!  THERE  IS  NO  VALUE.\n\n\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"\tDATA_LEVEL -> "<< index <<" = "<<temp -> data<<"\n\n";
        temp = temp -> next;
        index--;
    }
    cout<<endl;
}

int main()
{
    cout<< "\n\n\t\tLET'S  START\n";
    cout<< "\t\t-----  -----\n\n\n\n";
    cout<< "\t\t\t\t\t-----\n";
    cout<< "\t\t\t\t******| STACK |******\n";
    cout<< "\t\t\t\t\t-----\n\n\n\n";

    while(1)
    {
        int key,data;

        cout<<"\t\t\tIF YOU WANT TO INSERT DATA PRESS  ->(1)\n\n";
        cout<<"\t\t\tIF YOU WANT TO DELETE DATA PRESS  ->(2)\n\n";
        cout<<"\t\t\tIF YOU WANT TO SEE DATA PRESS  ->(3)\n\n";
        cout<<"\t\t\tIF YOU WANT TO EXIT PRESS  ->(0)\n\n";
        cout<<"\n\t\t\tPLEASE PRESS ANY KEY BETWEEN (0) <-> (3) =  ";

        cin >> key;

        if(key == 0)
            break;

        else if(key == 1)
        {
            cout<<"\n\n\tPLEASE ENTER THE DATA = ";

            cin>> data;

            push(data);

            cout<< "\n\n\t"<<data<<"  IS INSRERTED.\n\n";
        }
        else if(key == 2)
        {
            pop();
        }
        else if(key == 3)
        {
            printf("\n\n");

            if(head != NULL)
            {
                cout<< "\tLET'S SEE STACK :\n";
                cout<< "\t----- --- -----\n\n";
            }
            print();
        }
        else
            cout<<"\n\n\tOPS!  SORRY  YOU  PRESS  WRONG  KEY  HeHe.\n\n\n";
    }

    cout<< "\n\n\n\n\t\t\t\t\t\t------\n\t\t\t\t\t    |*| THANKS |*|\n";
    cout<< "\t\t\t\t\t\t------\n\n\n";

    return 0;
}
