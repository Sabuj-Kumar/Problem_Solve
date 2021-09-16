#include<stdio.h>
int b[100][100];
int main()
{
    int a[100][100],c[100],i,j,m=0,n=0,size,store=0;
    scanf("%d",&size);
    for( i = 0; i < size; i++ )
      for( j = 0; j < size; j++ )
        a[i][j] = i*size+j+1;

    for( i = 0; i < size; i++ )
     {
       for( j = 0; j < size; j++ )
       {
          if ( i == j ||  j > i )
            {
              b[i][j] = a[m][n];
              n++;
              store = b[i][j];
            }
          if( n == size )
            {
              m++;
              n=0;
            }
       }
     }

    for( i = 0; store < size * size; i++ )
      c[i]= ++store;
    n=0;
    for( i = 0; i < size; i++ )
    {
      for( j = 0; j < size; j++ )
       {
           if ( b[i][j] == 0 )
           {
              b[i][j]=c[n];
              n++;
           }
       }
    }
    for( i = 0; i < size; i++ )
    {
      for( j = 0; j < size; j++ )
       printf("%d ",b[i][j]);
       printf("\n");
    }
 return 0;
}
