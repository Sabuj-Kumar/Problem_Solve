#include<stdio.h>
#include<iostream>
#include<math.h>

#define sf scanf
#define pf printf
#define m 100010

int a[m];
int b[m];

int seive()
{
    int i = 0,j = 0,root = 0;

    a[0] = 1;
    a[1] = 1;

    root = sqrt(m);

    for(i = 4; i < m; i+=2)
      a[i] = 1;

    for(i = 3; i <= root; i+=2)
       if(a[i] == 0)
         for(j = i*i; j < m; j+=i)
            a[j] = 1;

    j = 0;

    for(i = 2; i < m; i++)
    {
       if(a[i] == 0)
       {
          b[j] = i;
          j++;
       }
    }
    return j;
}
int main()
{
    int recive = seive();
    int input,i,j;

    while(sf("%d",&input) && input != 0)
    {
       int count = 0,flage = 0,sum = 0;

       for(i = 0; b[i] <= input; i++)
       {
           for(j = i; j < recive; j++)
           {
               sum += b[j];

               if(sum == input)
               {
                   flage = 1;
                   break;
               }
               else if(sum > input)
                 break;
           }
           if(flage == 1)
           {
               count++;
               flage = 0;
           }
           sum = 0;
       }
       pf("%d\n",count);
    }
    return 0;
}
