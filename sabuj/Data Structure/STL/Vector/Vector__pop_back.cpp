#include<iostream>
#include<vector>
#include<stdio.h>
#include<iterator>
#include<string>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    vector<int> myvector;

    int i,N = 5;

///   cout<<"Enter The Total Element's Number..  ";
///    cin>>N;

    for( i = 1; i <= N; i++ )
        myvector.push_back(i);

    for( i = 0; i < myvector.size(); i++ )
        cout<<myvector[i]<<" ";

//    for( i = 0; i != myvector.size(); i++ )
//    {
//       myvector.pop_back();
//    }
    while( !myvector.empty())
      myvector.pop_back();

    printf("\n\n");

    for( i = 0; i < myvector.size(); i++ )
        cout<<myvector[i]<<" ";

    cout<<endl;

    return 0;
}
