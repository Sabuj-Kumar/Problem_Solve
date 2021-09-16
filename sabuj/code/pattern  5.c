#include<stdio.h>
int main()
{
    int i,j,size;
    scanf("%d",&size);
    int a[size][size];
    for( i = 0; i < size; i++ )
      for( j = 0; j < size; j++ )
       a[i][j] = i*size+j+1;

    for( i = size-1; i >= 0; i-- )
    {
      for( j = size-1; j >= 0; j-- )
       printf("%d ",a[i][j]);
      printf("\n");
    }
}
