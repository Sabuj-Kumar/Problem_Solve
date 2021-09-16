#include<stdio.h>
int main()
{
    int a[100][100],size,i,j;
    scanf("%d",&size);
    for( i = 0; i < size; i++ )
    {
        for( j = 0; j < size; j++ )
        {
           a[i][j] = j;
           printf("%d ",a[i][j]);
        }

        printf("\n");
    }
}
