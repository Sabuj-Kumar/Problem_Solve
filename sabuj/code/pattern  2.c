#include<stdio.h>
int main()
{
    int a[100][100],i,j,size;
    scanf("%d",&size);
    for ( i = 0; i < size; i++ )
     for ( j = 0; j < size; j++ )
        a[i][j] = j;
    for ( i = 0; i < size; i++ )
    {
        for ( j = 0; j < size; j++ )
        printf("%d ",a[j][i]);
        printf("\n");
    }

}
