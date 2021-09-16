#include<stdio.h>
#include<iostream>
#include<math.h>
#define n 10000000

int a[n] = {0};
int b[n/2] = {0};

using namespace std;

void seive()
{
    int i,j,root = sqrt(n);

    for(i = 4; i < n; i += 2)
      a[i] = 1;

    for(i = 3; i < root; i += 2)
       if(a[i] == 0)
         for(j = i*i; j < n; j += i)
            a[j] = 1;
   j = 0;

   for( i = 2; i < n; i++)
   {
       if(a[i] == 0)
       {
           b[j] = i;
           j++;
       }
   }
}

int main()
{
    seive();

    int input,m;

    while(scanf("%d",&input) && input > 0)
    {
        int count = 0;

        m = input / 2;

        for(int i = 0; i < m; i++)
            if(input % b[i] == 0)
                count++;

        printf("%d : %d\n",input,count);
    }

    return 0;
}
