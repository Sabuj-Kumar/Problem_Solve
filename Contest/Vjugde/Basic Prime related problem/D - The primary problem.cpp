#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 1000010
using namespace std;

bool a[ n ];

void seive()
{
    int i,j, root = sqrt( n );

    for(i = 2; i < root; i++)
      if(a[ i ] == 0)
        for(j = i * 2; j < n; j += i)
          a[ j ] = 1;
}
int main()
{
    seive();

    //freopen("input.text","r",stdin);

    int input,i,p,m;

    while(scanf("%d",&input) && input)
    {
        bool flag = false;
        int check = 0;

        for(i = 2; i < input; i++)
        {
            if(a[ i ] == 0)
            {
                check = input-i;

                if(a[check] == 0)
                {
                    m = i;
                    p = check;
                    flag = true;
                    break;
                }
            }
        }
        if(flag == true)
            printf("%d:\n%d+%d\n",input,m,p);

        else
            printf("%d:\nNO WAY!\n",input);
    }
    return 0;
}
