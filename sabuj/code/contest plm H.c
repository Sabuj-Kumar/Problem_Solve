#include<stdio.h>
int main()
{
    int n,r,i,j,swap=0,size,store1=1,store2=1,store3=1,result=0;
    scanf("%d",&size);
    for( i = 1; i <= size; i++ )
    {
        scanf("%d %d",&n,&r);
        n = n % 1000003;
        r = r % 1000003;
        if( n < r )
        {
            swap = n;
            n = r;
            r = swap;
        }
        if ( n == 0 || r == 0 )
         printf("Case %d: 1\n",i);
        else
        {
            for ( j = 1; j <= n; j++ )
                store1 *= j;
            for ( j = 1; j <= r; j++ )
                store2 *= j;
            for ( j = 1; j <= n-r; j++ )
                store3 *= j;
            if( store1 != 0 )
            {
                result = (store1%1000003)/((store2*store3)%1000003);
                result = result % 1000003;
                printf("Case %d: %d\n",i,result);
                store1=1;
                store2=1;
                store3=1;
            }
        }
    }
    return 0;
}
