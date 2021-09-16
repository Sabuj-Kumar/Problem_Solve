#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
    int test;

    while(scanf("%d",&test)==1)
    {
        while(test--)
        {
           int a[30100] = {0},b,i;
           scanf("%d",&b);

           for(i = 0; i < b; i++)
              scanf("%d",&a[i]);

           sort(a,a+b);

           for(i = 0; i < b; i++)
              printf("%d ",a[i]);

           printf("\n");

           if(b%2)
             printf("%d\n",a[b/2]);

           else
             printf("%d\n",a[b/2-1]);
        }
    }
    return 0;
}
