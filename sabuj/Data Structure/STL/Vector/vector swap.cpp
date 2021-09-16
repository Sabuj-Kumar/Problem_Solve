#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
    vector<int> myvector;
    vector<int> myvector1;

    int a = 1,b = 1,i;

    cout<<"Enter The First Elements..";

    while(a)
    {
        cin>>a;

        myvector.push_back(a);
    }

    cout<<"Enter The Second Elements..";

    while(b)
    {
        cin>>b;

        myvector1.push_back(b);
    }

    myvector.swap(myvector1);

    cout<<"First Vector: ";

    for( i = 0; i < myvector.size(); i++ )
        cout<<myvector[i]<<" ";

    printf("\n\n");

    cout<<"Second Vector: ";

    for( i = 0; i < myvector1.size(); i++ )
        cout<<myvector1[i]<<" ";

     printf("\n");

     return 0;
}

