#include<stdio.h>
#include<string.h>
int main()
{
    int input,j,i = 0,mod;
    char output[10000];
    while( scanf("%d",&input) )
    {
        if ( input < 0 )
          break;
        if ( input == 0 )
            printf("0");
        else
        while ( input > 0 )
        {
            mod = input % 3;
            output[ i ] = mod + 48;
            input /= 3;
            i++;
        }
        output[ i ] = '\0';
        for( j = --i ; j >= 0; j--)
         printf("%c",output[j]);
         printf("\n");
        i = 0;
    }
    return 0;
}
