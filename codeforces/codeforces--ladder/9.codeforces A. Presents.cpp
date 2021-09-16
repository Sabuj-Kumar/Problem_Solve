#include<stdio.h>
#include<ostream>

using namespace std;

int main()
{
    int n = 0,i = 0,j = 1,k = 0;

    scanf("%d",&n);

    int input[n] = {0},output[n] = {0};

    for( i = 1; i <= n; i++ )
      scanf("%d",&input[i]);

    for( i = 1; i <= n; i++ )
    {
        for( j = 1; j <= n; j++ )
        {
            if( i == input[ j ])
            {
                output[ k ] = j;
                k++;
            }
        }
    }
    for( i = 0; i < n; i++ )
     printf("%d ",output[ i ]);

    printf("\n");

    return 0;
}
