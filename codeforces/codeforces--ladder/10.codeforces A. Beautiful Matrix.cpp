#include<stdio.h>
#include<ostream>

using namespace std;

int main()
{
    int a[5][5] = {0},i,j,p = 0,q = 0;

    ///while( 1 )
    {
        int flag = 0,sum = 0;

        for( i = 0; i < 5; i++ )
          for( j = 0; j < 5; j++ )
             scanf("%d",&a[i][j]);

        for( i = 0; i < 5; i++ )
        {
            for( j = 0; j < 5; j++ )
            {
                if( a[i][j] == 1 )
                {
                    p = i+1;
                    q = j+1;

                    flag = 1;
                    break;
                }
            }
            if( flag == 1 )
                break;
        }

        //printf("%d %d\n",p,q);

        if( p == 3 && q != 3 )
        {
            if( q > 3)
            {
                sum = q - 3;
                printf("%d\n",sum);
            }
            else
            {
                sum = 3 - q;

                printf("%d\n",sum);
            }
        }
        else if( q == 3 &&  p != 3 )
        {
            if( p > 3)
            {
                sum = p - 3;
                printf("%d\n",sum);
            }
            else
            {
                sum = 3 - p;

                printf("%d\n",sum);
            }
        }
        else if( p > 3 && q > 3 )
        {
            sum = (p - 3) + (q - 3);

            printf("%d\n",sum);
        }
        else if( p < 3 && q < 3)
        {
            sum = (3 - p) + (3 - q);

            printf("%d\n",sum);
        }
        else if( p == 3 && q == 3)
        {
           printf("0\n");
        }
        else if( p > 3 && q < 3 )
        {
            sum = (p - 3) + (3 - q);

            printf("%d\n",sum);
        }
        else if( p < 3 && q > 3 )
        {
            sum = (q - 3) + (3 - p);

            printf("%d\n",sum);
        }
    }
    return 0;
}
