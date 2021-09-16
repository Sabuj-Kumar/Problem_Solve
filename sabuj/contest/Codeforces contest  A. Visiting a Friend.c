#include<stdio.h>
int main()
{
    int a[101],b[101],i,j,p,n,m,flag = 0,cheek = 0;
    scanf("%d %d",&n,&m);

    for ( i = 0; i < n; i++ )
     scanf("%d %d",&a[i],&b[i]);

    if ( b[ n - 1 ] == m )
    {
        i = 0;
        j = 1;
        if ( a[0] != 0 )
          printf("NO\n");
        else
        {
          while( n-- )
          {
             if ( n > 0 )
              {
                if ( b[ i ] >= a[ i ] )
                {
                    flag = 1;
                     i++;
                     j++;
                }
                else
                {
                    for ( p = 0; p < j; p++ )
                    {
                        if ( a[ p ] <= a[ j ])
                        {
                            flag = 1;
                            cheek = 1;
                            break;
                        }
                        else
                         cheek = 0;
                    }
                    if ( cheek = 0 )
                    {
                        flag = 0;
                        break;
                    }
                }
              }
          }
          if ( flag == 1 )
            printf("YES\n");
          else
            printf("NO\n");
        }
    }
    else
      printf("NO\n");

    return 0;
}
