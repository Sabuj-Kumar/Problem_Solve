#include<stdio.h>
int main()
{
    int i,t;

    scanf("%d",&t);

    for( i = 0; i < t; i++ )
    {
        int n,j = 0,donate = 0,sum = 0,flag = 1;

        char a[20];

        printf("Case %d:\n",i+1);

        scanf("%d",&n);

        for ( j = 0; j < n; j++ )
        {
            scanf("%s",a);

            if( a[ 0 ] == 'd')
            {
                scanf("%d",&donate);

                sum += donate;
            }
            else
            {
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
