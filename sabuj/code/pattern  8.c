#include<stdio.h>
int main()
{
    int i,j,size,m=0,n=0;
    scanf("%d",&size);

    int a[size][size],b[size][size];
    for( i = 0; i < size; i++ )
      for( j = 0; j < size; j++ )
         a[i][j] = i*size+j+1;

    for( i = 0; i < size; i++ )
    {
        if( i % 2 == 0 )
         for( j = 0; j < size; j++ )
         {
             b[m][n] = a[i][j];
             n++;
         }
        else
         for( j = size-1; j >= 0; j-- )
         {
             b[m][n] = a[i][j];
             n++;
         }
         m++;
         n=0;
    }
    for( i = 0; i < size; i++ )
    {
     for( j = 0; j < size; j++ )
       printf("%d ",b[j][i]);
     printf("\n");
    }
  return 0;
}
