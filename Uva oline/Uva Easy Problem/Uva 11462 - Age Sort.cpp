#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n;

    while( scanf("%d",&n) && n != 0 )
    {
        int i,j,k = 0,input = 0,a[101] = {0},max = 0,flag = 1;

        for( i = 0; i < n; i++ )
        {
            scanf("%d",&input);
            a[input]++;

            if( max < input)
              max = input;
        }

        for( i = 1; i <= max; i++ )
        {
            if( a[ i ] != 0 )
            {
                for( j = 0; j < a[i]; j++ )
                {
                    if( flag == 1 )
                    {
                       printf("%d ",i);
                       flag = 2;
                    }
                    else if( flag == 2 )
                    {
                        printf("%d",i);
                        flag = 0;
                    }
                    else
                        printf(" %d",i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

