#include<stdio.h>
int main()
{
    int T,a[11],i,j,N,swap,k;
    scanf("%d",&T);

    for( i = 1; i <= T; i++ )
    {
        scanf("%d",&N);

        for( j = 0; j < N; j++ )
         scanf("%d",&a[j]);

        for (j = 0 ; j < ( N - 1 ); j++)
          for (k = 0 ; k < N - j - 1; k++)
            if (a[k] > a[k+1])
            {   swap  = a[k];
                a[k]  = a[k+1];
                a[k+1] = swap;
            }

        printf("Case %d: %d\n",i,a[N/2]);
    }
    return 0;
}
