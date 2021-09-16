#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int test,i;

    sf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        int ar[110] = {0},sum  = 0,a,b,c,count = 0,j = 0;

        sf("%d %d %d",&a,&b,&c);

        for(j = 0; j < a; j++)
           sf("%d",&ar[j]);

        if(a <= b)
        {
            for(j = 0; j < a; j++)
            {
                sum += ar[j];

                if(sum <= c)
                   count++;

                else
                    break;
            }
        }
        else
        {
            for(j = 0; j < b; j++)
            {
                sum += ar[j];

                if(sum <= c)
                  count++;

                else
                    break;
            }
        }
        pf("Case %d: %d\n",i,count);
    }
    return 0;
}
