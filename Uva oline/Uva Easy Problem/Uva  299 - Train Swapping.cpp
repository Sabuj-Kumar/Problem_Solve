#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int test,i;

    scanf("%d",&test);

    for(i = 0; i < test; i++ )
    {
        int l,swap = 0,count = 0;

        scanf("%d",&l);

        int input[l];

        for( int j = 0; j < l; j++ )
           scanf("%d",&input[j]);

        for( int j = 0; j < (l - 1); j++ )
        {
            for( int k = 0; k < (l - j - 1); k++ )
            {
                if(input[k+1] < input[ k ])
                {
                    swap = input[k+1];
                    input[k+1] = input[k];
                    input[k] = swap;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
}
