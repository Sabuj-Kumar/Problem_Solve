#include<stdio.h>
int main()
{
    int T,N,input,i,j,max=0;
    scanf("%d",&T);
    for ( i = 1; i <= T; i++ )
    {
        scanf("%d",&N);
        for( j = 0; j < N; j++ )
        {
            scanf("%d",&input);
            if ( max < input )
              max = input;
        }
        printf("Case %d: %d\n",i,max);
        max = 0;
    }
    return 0;
}
