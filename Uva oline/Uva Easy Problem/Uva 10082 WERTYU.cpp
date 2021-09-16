#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    string a="`1234567890-=QWERTYUIOP[]ASDFGHJKL;'\\ZXCVBNM,./";
    string input;

    while(getline(cin,input))
    {
        int i,j;

        for(i = 0; i < input.size(); i++)
            for(j = 0; j < a.size(); j++)
                if(input[ i ] == a[ j ])
                     input[ i ] = a[ j-1 ];

        cout<<input<<"\n";
    }
    return 0;
}
