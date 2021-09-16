#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a[1000],i,n;

    scanf("%d",&n);

    for( i = 0; i < n; i++ )
        scanf("%d",&a[i]);

    int b = a[0];

    for( i = 1; i < n; i++ )
      b = (b^a[i]);

    printf("%d\n",b);

    return 0;
}
