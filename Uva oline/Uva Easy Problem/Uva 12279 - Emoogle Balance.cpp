#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int test = 0,k = 0;

    while(cin>>test && test != 0)
    {
        int a[2000] = {0},i,count1 = 0,count2 = 0;

        for(i = 0; i < test; i++)
        {
            cin>>a[i];

            if(a[i] == 0)
              count1++;

            else
              count2++;
        }
        cout<<"Case "<<++k<<": "<<count2-count1<<endl;
    }
    return 0;
}
