#include<stdio.h>
int main()
{
    int i,j,n,sum = 0;
    scanf("%d",&n);
    for ( i = 1; i <= n; i++ )
    {
      for ( j = 1; j <= i; j++ )
      {
        if ( i == 1 )
        {
            sum += j;
           printf("%d + ",i);
        }
        else
        {
            sum += j;
          if( j == 1 )
             printf("( %d",j);
          else if ( j <= i )
          {
            printf(" + %d",j);
            if ( j == i )
            printf(" )");
          }
          if ( j == i && i != n )
             printf(" + ");
        }
       }
    }
    printf("\n\nTotal Sum Is = %d.\n",sum);
    return 0;
}
