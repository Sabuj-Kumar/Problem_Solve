#include<stdio.h>
int main()
{
    int N,i,a;
    scanf("%d",&N);

    for( i = 0; i < N; i++ )
    {
        scanf("%d",&a);
        if( a <= 40 )
        {
            if( ( 40 -  a ) < 3 )
            printf("40\n");
            else
            printf("%d\n",a);
        }
        else if ( a > 40 )
        {
            int b = a;

            while( b % 5 != 0 )
            b++;

            if( ( b - a ) < 3 )
            printf("%d\n",b);
            else
            printf("%d\n",a);
        }
    }
    return 0;
}
