#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;

    Node *left;

    Node *right;
};

Node *creat_node(int data)
{
    Node *node = new Node();

    node -> data = data;

    node -> left = NULL;

    node -> right = NULL;

    return node;
}

void pre_order_Travase(Node *root)
{
    if(root == NULL)
        return;

    cout << root -> data << " ";

    pre_order_Travase(root -> left);

    pre_order_Travase(root -> right);
}

void In_order_Travase(Node *root)
{
    if(root == NULL)
        return;

    In_order_Travase(root -> left);

    cout << root -> data << " ";

    In_order_Travase(root -> right);
}
void post_order_Travase(Node *root)
{
    if(root == NULL)
        return;

    post_order_Travase(root -> left);

    post_order_Travase(root -> right);

    cout << root -> data << " ";
}

Node *insert_node(Node *node,int data)
{
    if(node == NULL)
      return creat_node(data);

    if(node -> data > data) node -> right = insert_node(node -> right,data);

    else node -> left = insert_node(node -> left,data);
}
int main()
{
    int Size,input;

    cout << "Enter The Tree Length  =   ";

    cin >> Size;

    Node *root = NULL;

    cout << "Enter The Data  =  ";

    for(int i = 0; i < Size; i++)
    {
        cin >> input;

        if(i == 0) root = insert_node(root,input);

        else insert_node(root,input);
    }
    while(1)
    {
        int key;

        cout << "Press 1 For Pre_order Print.\n";
        cout << "Press 2 For In_order Print.\n";
        cout << "Press 3 For Post_order Print.\n";
        cout << "Press 0 For Exit.\n\n";

        cout << "Press key\t  =  ";
        cin >> key;

        if(key == 1)
            pre_order_Travase(root);

        else if(key == 2)
            In_order_Travase(root);

        else if(key == 3)
            post_order_Travase(root);

        else if(key == 0)
            break;

        else
            cout << "\nWrong Key.";

        cout <<"\n\n";
    }
    return 0;
}
