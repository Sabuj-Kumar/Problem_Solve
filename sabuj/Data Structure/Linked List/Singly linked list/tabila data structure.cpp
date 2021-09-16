#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct node{
    int x;
};

void print_array(struct node* a, int indx){
    cout<<"Array: ";
    for(int i=0;i<=indx;i++){
        cout<<a[i].x<<" ";
    }
    cout<<endl;//for new line
}

void array_insert_last(struct node* a, int indx, int v){
    a[indx].x = v;
}

void array_insert_first(struct node* a, int indx, int v){

    for(int i=indx;i>0;i--){
        a[i].x = a[i-1].x; // shift every value to the right
    }
    a[0].x = v;
}

void array_delete_first(struct node* a, int indx){
    for(int i=0;i<indx;i++){
        a[i].x = a[i+1].x; // shift every value to the left
    }
}

int main()
{
    struct node* arr;
    int max_item = 10;//static change of max_item
    arr=new node[max_item];
    //arr = (struct node*)malloc(10*sizeof(struct node));
    string s;
    int value;
    int index = -1;
    while(1)
    {
        cin>>s; //s takes input like "insert-first"/"in sert-last"/"delete-first"/"delete-last"
        if(s=="insert-last")
        {
            cin>>value;
            if(index<(max_item-1))
            { // check whether you can understand why max_item-1 is used here!!
                index++;
                array_insert_last(arr, index, value);
            }
            else
            {
                cout<<"Memory overflow!"<<endl; // number of items will be greater than max_item if this insert happens
            }
        }
        else if(s=="insert-first")
        {
            cin>>value;
            if(index<(max_item-1))
            { // check whether you can understand why max_item-1 is used here!!
                index++;
                array_insert_first(arr, index, value);
            }
            else{
                cout<<"Memory overflow!"<<endl; // number of items will be greater than max_item if this insert happens
            }
        }
        else if(s=="delete-last")
        {
            if(index>-1)
            {
                index--;
            }
            else
            {
                cout<<"Memory underflow!"<<endl; // number of items will be lesser than 0 if this delete happens
            }
        }
        else if(s=="delete-first")
        {
            if(index>-1)
            {
                array_delete_first(arr, index);
                index--; // check why I did this!!
            }
            else
            {
                cout<<"Memory underflow!"<<endl; // number of items will be lesser than 0 if this delete happens
            }
        }
        else if(s=="exit")
        {
            break;
        }
        else
        {
            cout<<"Operations not identified!"<<endl;
        }
        print_array(arr, index); //for printing the whole array after this operation
    }

    return 0;
}
