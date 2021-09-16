#include<stdio.h>
#include<stdlib.h>

int main()
{

    int i,j,a[100][100];

    for( i=0;i<100;i++)
    {
        for( j=0;j<100;j++)
        {
            a[i][j]=rand()%10;
        }
    }
    for( i=0;i<100;i++)
    {
        for( j=0;j<100;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
