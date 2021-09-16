#include<stdio.h>
int main()
{
    int a,sum = 0,i,flag = 0;
    scanf("%d",&a);
    for( i = 1; i <= a/2; i++ )
    {
        sum += i;
        if( sum ==  a)
        {
            flag = 1;
            break;
        }
    }
    if ( flag == 1 )
     printf("This Is Perfect Number.\n");
    else
     printf("This Is Not Perfect Number.\n");

}
