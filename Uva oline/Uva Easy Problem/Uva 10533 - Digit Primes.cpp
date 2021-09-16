#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 1000002

int a[n];
int b[n];

using namespace std;

int check_prime(int a)
{
   int mod = 0;

   while(a)
   {
       mod += a % 10;
       a /= 10;
   }
   return mod;
}

void Digit_Prime(int prime[])
{
    int count = 0;

    for(int i = 2; i < n; i++)
    {
        if(a[ i ] == 0)
        {
            int p = 0;

            p = check_prime(i);

            if(a[p] == 0)
               b[ i ] = 1;
        }
    }
}
void seive()
{
    a[0] = -1;
    a[1] = -1;

    int root = sqrt(n);

    for(int i = 4; i < n; i += 2)
        a[ i ] = -1;

    for(int i = 3; i < root; i += 2)
        if(a[ i ] == 0)
            for(int j = i * i; j < n; j += i)
               a[ j ] = -1;


    Digit_Prime(a);

    for(int i = 1; i < n; i++)
        b[ i ] = b[ i ] + b[ i - 1];
}

int main()
{
    ///freopen("input.txt","r",stdin);
    seive();

    int test;

    scanf("%d",&test);

    while(test--)
    {
        int low,high;

        scanf("%d %d",&low,&high);

        low--;

        printf("%d\n",b[ high ] - b[ low]);
    }

    return 0;
}
