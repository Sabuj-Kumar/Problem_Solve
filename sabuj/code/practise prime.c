#include<stdio.h>
int main()
{
    int a,b,i,j,swap,flag,count=0;
    scanf("%d %d",&a,&b);
    if ( a > b )
    {
      a = swap;
      a = b;
      b = swap;
    }
    for( i = a; i <= b; i++ )
    {
        flag = 1;
        for( j = 2; j < i; j++)
        {
            if( i % j == 0 )
            {
                flag = 0;
                break;
            }
        }
        if ( flag == 1 )
          printf("%d ",i);
    }
    return 0;
}
