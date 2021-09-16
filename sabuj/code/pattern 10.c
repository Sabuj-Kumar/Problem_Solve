#include<stdio.h>
int b[100][100];
int main()
{
    int a[100][100],c[10000],d[10000],i,j,m=0,n=0,size;
    scanf("%d",&size);

    for( i = 0; i < size; i++ )
      for( j = 0; j < size; j++ )
        a[i][j] = i*size+j+1;

    for( i = 0; i < size; i++ )
     {
       for( j = 0; j < size; j++ )
       {
          if( i == j ||  j > i )
            {
              b[i][j] = a[m][n];
              n++;
            }
       }
       m++;
       n=0;
     }
     m=0;
    for( i = 0; i < size; i++ )
     for( j = 0; j < size; j++ )
      if ( b[i][j] != 0 )
      {
         c[m] = b[i][j];
         m++;
      }
    m=0;
    n=0;
    for( i = 0; i < size; i++ )
     for( j = 0; j < size; j++ )
     {
       if ( a[i][j] == c[m] )
         m++;
       else
        {
          d[n]=a[i][j];
          n++;
        }
     }
    m=0;
   for( i = 0; i < size; i++ )
   {
     for( j = 0; j < size; j++ )
     {
         if( b[i][j]==0 )
         {
             b[i][j] = d[m];
             m++;
         }
        printf("%d ",b[i][j]);

     }
      printf("\n");
   }

 return 0;
}
