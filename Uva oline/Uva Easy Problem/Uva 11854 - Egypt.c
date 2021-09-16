#include<stdio.h>
int main()
{
    int a,b,c;
    while( scanf("%d %d %d",&a,&b,&c)  && a||b||c != 0 )
    {
        int sum = 0;

        if ( a > b && a > c )
        {
          sum = (b*b) + (c*c) - (a*a);
           if( sum == 0)
             printf("right\n");
           else
             printf("wrong\n");
        }
        else if ( b > a && b > c )
        {
            sum = (a*a) + (c*c) - (b*b);
            if ( sum == 0 )
              printf("right\n");
            else
              printf("wrong\n");
        }
        else if ( c > a && c > b )
        {
            sum = (a*a) + (b*b) - (c*c);
            if ( sum == 0 )
              printf("right\n");
            else
              printf("wrong\n");
        }
        else
            printf("wrong\n");
    }

    return 0;
}
