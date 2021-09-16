#include<stdio.h>
#include<iostream>

using namespace std;

void sum( int *p,int size,int *add )
{
   for( int i = 0;i < size; i++ )
   {
        *add += *p;
        p++;
   }
}
int main()
{
    int a[100],i,n,d = 0,result;

    scanf("%d",&n);

    for( i = 0; i < n; i++ )
    {
        scanf("%d",&a[i]);
    }
    sum(a,n,&d);

    printf("%d",d);

    return 0;
}
