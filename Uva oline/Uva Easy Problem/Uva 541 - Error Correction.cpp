#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    ///freopen("input.txt","r",stdin);

    while(scanf("%d",&n) && n != 0)
    {
        int a[n][n],i,j,sum1 = 0,sum2 = 0,count1 = 0,count2 = 0,row = 0,column = 0;

        for(i = 0; i < n; i++)
          for(j = 0; j < n; j++)
            scanf("%d",&a[i][j]);

        for(i = 0; i < n; i++)
        {
            sum1 = 0;
            for(j = 0; j < n; j++)
               sum1 += a[i][j];

            if(sum1 % 2 != 0)
            {
                count1++;
                if(count1 == 1)
                    row = i;
            }
        }
        for(j = 0; j < n; j++)
        {
            sum2 = 0;
            for(i = 0; i < n; i++)
               sum2 += a[i][j];

            if(sum2 % 2 != 0)
            {
                count2++;
                if(count2 == 1)
                    column = j;
            }
        }
        if(count1 == 1 && count2 == 1)
            printf("Change bit (%d,%d)\n",row+1,column+1);

        else if(count1 == 0 && count2 == 0)
            printf("OK\n");

        else
            printf("Corrupt\n");
    }
    return 0;
}
