#include<stdio.h>
#include<string.h>
int main()
{
    char input[1000];

    while( gets(input) )
    {
       int i,count = 0,flage = 1;
       for ( i = 0; input[ i ] != '\0'; i++ )
        {
            if ( ( input[ i ] >= 'a' && input[ i ] <= 'z' ) || ( input[ i ] >= 'A' && input[ i ] <= 'Z' ) )
            {
                if ( flage == 1 )
                {
                    count++;
                    flage = 0;
                }
            }
            else
                flage = 1;
        }
        printf("%d\n",count);
    }
    return 0;
}
