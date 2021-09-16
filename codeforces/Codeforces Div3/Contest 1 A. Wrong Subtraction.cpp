#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long input;
    int n;

    cin>>input>>n;

    while(n--)
    {
        if(input % 10 == 0)
            input /= 10;
        else
            input--;
    }
    cout<<input<<endl;

    return 0;
}
