#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int a,b,c,d,l;

    while(sf("%d %d %d %d %d",&a,&b,&c,&d,&l) && (a+b+c+d+l) != 0)
    {
        int i = 0,sum = 0,count = 0;

        for( i = 0; i <= l; i++ )
        {
            sum = a*i*i+b*i+c;

            if( sum % d == 0)
              count++;
        }
        pf("%d\n",count);
    }
    return 0;
}
