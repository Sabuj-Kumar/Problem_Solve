#include<stdio.h>
int main()
{
    int a,b,c,N;
    scanf("%d",&N);
    while( N-- )
    {
        scanf("%d %d %d",&a,&b,&c);
        if( a > b && a > c )
        {
            if( ( b + c ) > a )
            printf("OK\n");
            else
            printf("Wrong!!\n");
        }
        else if(  b > a && b > c )
        {
            if( ( a + c ) > b )
            printf("OK\n");
            else
            printf("Wrong!!\n");
        }
        else
        {
            if( ( a + b ) > c )
            printf("OK\n");
            else
            printf("Wrong!!\n");
        }
    }

    return 0;
}
