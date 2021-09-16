#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n,input,sum = 0;

    cin>>n;

    int a[ n + 1 ];

    for( int  i = 1; i <= n; i++ )
    {
        cin>>input;

        sum += input;

        a[i] = sum;
    }

    int start_position,end_position;

    cout<<"Enter The Start Position And Last Position..  ";

    while( scanf( "%d %d",&start_position,&end_position ) == 2 )
    {
        if( start_position == 1 )
           cout<< a[ end_position ]<<endl;

        else
           cout<<( a[ end_position ] - a[ --start_position ] )<<endl;

        cout<<endl;

        cout<<"Enter The Start Position And Last Position..  ";
    }

}
///1 2 3 4 5 6 7 8 9 10
