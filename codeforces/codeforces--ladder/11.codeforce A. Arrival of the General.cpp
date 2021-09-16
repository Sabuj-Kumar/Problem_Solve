#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int n,i,max_pos = 0,min_pos = 0,output = 0;

    scanf("%d",&n);

    int a[101] = {0},max = 0,min = 101;

    for( i = 0; i < n; i++ )
    {
        scanf("%d",&a[i]);

        if( a[i] > max )
        {
            max = a[i];

            max_pos = i+1;
        }
        if( a[i] <= min )
        {
            min = a[i];

            min_pos = i+1;
        }
    }
    if( min_pos > max_pos )
        output = (n - min_pos) + ( max_pos - 1 );

    else
      output = n - min_pos + ( max_pos - 1 ) - 1;

    printf("%d\n",output);

    return 0;
}
