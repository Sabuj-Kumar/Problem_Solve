#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int n,t = 0;

    while(sf("%d",&n) && n!= 0)
    {
        int input[n] = {0},sum = 0,div = 0,flag = 0,move = 0;

        for(int i = 0; i < n; i++)
        {
            sf("%d",&input[i]);

            sum += input[i];
        }

        div = sum / n;

        for( int i = 0; i < n; i++ )
        if(div < input[i])
        move += input[i] - div;

        pf("Set #%d\nThe minimum number of moves is %d.\n\n",++t,move);
    }
    return 0;
}
