#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000];
    int i,flag = 0;
    while(gets(str))
    {
        for( i = 0; str[i] != '\0'; i++ )
        {
            if( str[i] >= 'A' && str[i] <= 'Z' )
              flag = 1;
            else
            {
                flag = 0;
                break;
            }
        }
        if( str[0] >= 'A' && str[0] <= 'Z' && flag == 0 )
        {
            for( i = 1; str[i] != '\0'; i++ )
            {
                if( str[i] >= 'A' && str[i] <= 'Z' )
                    str[i] = str[i] + 32;
            }
        }
        else if( flag == 0 )
        {
            str[0] = str[0] - 32;
            for( i = 1; str[i] != '\0'; i++ )
            {
                if( str[i] >= 'A' && str[i] <= 'Z' )
                    str[i] = str[i] + 32;
            }
        }
        else
        {
            for( i = 0; str[i] != '\0'; i++ )
              str[i] = str[i] + 32;
        }
        printf("%s\n",str);
    }
    return 0;
}
