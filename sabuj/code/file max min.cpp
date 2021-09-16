#include <stdio.h>
#include <conio.h>
int main()
{
    int  n = 10;

    char c;

    int nums[n];

    int min = 0,max = 0,i = 0,a;

    FILE *file;

    file = fopen("text.txt","r");

    while( fscanf( file,"%d:%c",&a,&c) )
    {
        nums[ i ] = a;

        printf("%d ",nums[ i ]);

        i++;
    }

    fclose(file);

    for( i = 0; i < n; i++)
    {
          if( i == 0 )
          {
              max = nums[ i ];

              min = nums[ i ];
          }
          if( nums[ i ] > max)
            max = nums[ i ];

          if ( nums[ i ] < min)
            min = nums[ i ];

    }
    printf("\nMaximum: %d\n", max);

    printf("Minimum: %d\n", min);

    return 0;
}
