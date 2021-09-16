#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

long long power(long long a,long long b)
{
    long long i,sum = 1;

    for(i = 0; i < b; i++)
        sum *= a;

    return sum;
}
int main()
{
    long long input,check = 0,i = 0;

    cin>>input;

    if(input == 0)
    {
        cout<<input<<endl;
        return 0;
    }

    input++;

    if(input % 2 == 0)
        cout<<(input/2)<<endl;

    else
        cout<<input<<endl;

    return 0;
}
