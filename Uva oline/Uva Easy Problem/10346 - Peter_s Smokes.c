#include<stdio.h>
int main()
{
    int a,b;
    while( scanf("%d %d",&a,&b)!=EOF )
    {
        int n;
        n = a;
        while ( n >= b )
        {
           a += n / b;
           n = ( n / b ) + ( n % b );
        }
        printf("%d\n",a);
    }
     return 0;
}
