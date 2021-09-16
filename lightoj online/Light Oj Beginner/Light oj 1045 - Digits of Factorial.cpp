#include<stdio.h>
#include<bits/stdc++.h>

long long a[1000100];

using namespace std;

void fect()
{
    long long i,j,n;

    for(i = 0; i <= 1000; i++)
    {
        n = 1;

        for(j = 1; j <= i; j++)
           n *= j;

        if(i > 1)
          a[i] = n;

        else
          a[i] = 1;
    }
    for(i = 0; i <= 1000; i++)
        printf("%lld ",a[i]);
}
int main()
{
    fect();

    int test,i;

    scanf("%d",&test);

    for(i = 1; i <= test; i++)
    {
        long long number,base,count = 0,fct = 0;

        scanf("%lld %lld",&number,&base);
        fct = a[number];

        while(fct > 0)
        {
            fct /= base;
            count++;
        }
        printf("Case %d: %lld\n",i,count);
    }
    return 0;
}
