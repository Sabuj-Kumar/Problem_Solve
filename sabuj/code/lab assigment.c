#include<stdio.h>
int main()
{
    int a[100][100],b[100][100],c[100][100],d[100][100],n,m,p,q,i,j,k,mul=0;
    printf("Enter The Row And Column For First Array:  ");
    scanf("%d %d",&n,&m);

    printf("\nEnter The First Array Element's :\n");
    for( i = 0; i < n; i++ )
      for( j = 0; j < m; j++ )
        scanf("%d",&a[ i ][ j ]);

    printf("Enter The Row And Column For Second Array:  ");
    scanf("%d %d",&p,&q);

    printf("\nEnter The second Array Element's :\n");
    for( i = 0; i < p; i++ )
      for( j = 0; j < q; j++ )
        scanf("%d",&b[ i ][ j ]);

    for( i = 0; i < n; i++ )
      for( j = 0; j < m; j++ )
        c[ i ][ j ] = a[ i ][ j ] - b[ i ][ j ];

    printf("\nDifference Between Two Array Is:\n\n");
    for( i = 0; i < n; i++ )
    {
      for( j = 0; j < m; j++ )
        printf("%d  ",c[ i ][ j ]);
        printf("\n");
    }
    printf("\nScalar Multiplication of Matrix. For A Array.\n");
    printf("\nEnter The integer Number : ");
    scanf("%d",&mul);

    for( i = 0; i < n; i++ )
     for( j = 0; j < m; j++ )
      c[ i ][ j ] = mul * a[ i ][ j ];

    printf("\n");

    for( i = 0; i < n; i++)
    {
       for( j = 0; j < m; j++ )
        printf("%d  ", c[ i ][ j ]);
        printf("\n");
    }
    if( m == p )
     for( i = 0; i < n; i++ )
      for( j = 0; j < m; j++ )
       for( k = 0; k < p; k++ )
        d[ i ][ j ] += a[ i ][ k ] * b[ k ][ j ];

     printf("\nMultiply two matrices.\n\n");
     if( m == p)
      for( i = 0; i < n; i++ )
      {
         for( j = 0; j < m; j++ )
           printf("%d  ",d[ i ][ j ]);
        printf("\n");
      }
     else
      printf("Not Multiple Between Two Array.\n");

    return 0;
}
