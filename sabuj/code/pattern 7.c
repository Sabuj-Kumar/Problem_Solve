#include<stdio.h>
int main()
{
    int i,j,size;
    scanf("%d",&size);
    int a[size][size];

    for( i = 0; i < size; i++ )
      for( j = 0; j < size; j++ )
       a[i][j] = i*size+j+1;

    for( i = 0; i < size; i++ )
    {
      if( i % 2 ==  0)
        for( j = 0; j < size; j++ )
          printf("%d ",a[i][j]);
      else
       for( j = size-1; j >= 0; j-- )
          printf("%d ",a[i][j]);
      printf("\n");
    }
}
