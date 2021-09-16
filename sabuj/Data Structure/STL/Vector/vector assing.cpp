#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<iterator>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main()
{
    vector<int> myvector;
    vector<int> myvector1;
    vector<int> myvector2;
    vector<int> myvector3;

    int N = 10,i;

    myvector.assign(N,5);

    for( i = 0; i < myvector.size(); i++ )
        cout<<myvector[i]<<" ";

    printf("\n\n");

    for(  i = 1; i <= N; i++ )
     myvector1.push_back(i);

    for( i = 0; i < myvector1.size(); i++ )
        cout<<myvector1[i]<<" ";

    cout<<endl;

    cout<<endl;

    vector<int>::iterator it;

    it = myvector1.begin();

    myvector2.assign(it,myvector1.end());

    for( i = 0; i < myvector2.size(); i++ )
        cout<<myvector2[i]<<" ";

    cout<<endl;

    cout<<endl;

    int a[10] = {10,20,3,4,50,60,7,8,90,100};

    myvector3.assign(a,a+10);

    for( i = 0; i < myvector3.size(); i++ )
     cout<<myvector3[i]<<" ";

    cout<<endl;

    return 0;
}
