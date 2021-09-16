#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test,i;

    scanf("%d",&test);

    for(int i = 1; i <= test; i++)
    {
        int player = 0,start_player = 0,pass = 0,j = 0;

        scanf("%d %d %d",&player,&start_player,&pass);

        for(j = 1; j <= pass; j++)
        {
            if(start_player == player)
              start_player = 0;

            start_player++;
        }
        pf("Case %d: %d\n",i,start_player);
    }
    return 0;
}
