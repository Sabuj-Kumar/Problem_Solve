#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;

    while(scanf("%d %d",&n,&m) == 2)
    {
        int n1 = n;
        int m1 = m;

        if(n1 > m1)
            swap(n1,m1);

        int max = 0;

        for(int i = n1; i <= m1; i++)
        {
            int cycle = 1,j = i;

            while(j != 1)
            {
                if(j % 2 == 0)
                    j /= 2;

                else
                    j = 3*j+1;

                cycle++;
            }
            if(cycle > max)
                max = cycle;
        }
        printf("%d %d %d\n",n,m,max);
    }
    return 0;
}
