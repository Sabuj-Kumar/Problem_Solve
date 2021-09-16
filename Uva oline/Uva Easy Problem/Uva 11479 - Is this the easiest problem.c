#include<stdio.h>
int main()
{
    long long  i,N,a,b,c;
    scanf("%lld",&N);
    for ( i = 1; i <= N; i++ )
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if ( a < 0 || b < 0 || c < 0 )
            printf("Case %lld: Invalid\n",i);
        else if ( a == 0 || b == 0 || c == 0 )
           printf("Case %lld: Invalid\n",i);
        else if ( a == b && a == c && b == c )
           printf("Case %lld: Equilateral\n",i);
        else if ( a >= b && a >= c )
        {
            if ( ( b + c ) > a )
            {
                if ( a == b || a == c || b == c )
                   printf("Case %lld: Isosceles\n",i);
                else
                   printf("Case %lld: Scalene\n",i);
            }
            else
                printf("Case %lld: Invalid\n",i);
        }
        else if ( b >= a && b >= c )
        {
            if ( ( a + c ) > b )
            {
                if ( b == a || b == c || a == c )
                   printf("Case %lld: Isosceles\n",i);
                else
                   printf("Case %lld: Scalene\n",i);
            }
            else
                printf("Case %lld: Invalid\n",i);
        }
        else
        {
            if ( ( a +  b ) > c )
            {
                if ( c == a || c == b || a == b )
                   printf("Case %lld: Isosceles\n",i);
                else
                   printf("Case %lld: Scalene\n",i);
            }
            else
                printf("Case %lld: Invalid\n",i);
        }
    }
    return 0;
}
