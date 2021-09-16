#include<stdio.h>
int main()
{
    int i,N;
    scanf("%d",&N);
    for( i = 1; i <= N; i++ )
    {
        int a,b,c,flage = 1;
        scanf("%d %d %d",&a,&b,&c);

        if( a > 20 || b > 20 || c > 20 || a <= 0 || b <= 0 || c <= 0 )
        flage = 0;
        else
        flage = 1;

        if( flage == 1 )
        printf("Case %d: good\n",i);
        else
        printf("Case %d: bad\n",i);
    }
    return 0;
}
