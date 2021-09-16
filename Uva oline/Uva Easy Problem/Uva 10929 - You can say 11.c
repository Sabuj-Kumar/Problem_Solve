#include<stdio.h>
int main()
{
    char input[10001];

    while ( scanf("%s",input) )
    {
        long long i,sum = 0,cheek = 0;

        for ( i = 0; input[i] != '\0'; i++ )
        {
            cheek += input[i]-'0';
            if ( i % 2 == 0 )
              sum += input[i]-48;
            else
              sum -= input[i]-48;
        }
        if ( cheek == 0 )
            break;

        if ( sum % 11 == 0 )
         printf("%s is a multiple of 11.\n",input);
        else
         printf("%s is not a multiple of 11.\n",input);
    }
    return 0;
}
