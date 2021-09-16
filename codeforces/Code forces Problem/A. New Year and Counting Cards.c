#include<stdio.h>
#include<stdio.h>
int main()
{
    char str[1000];

    gets(str);
    int i,count = 0;
    for( i = 0; str[i] != '\0'; i++ )
    {
        if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' )
         count++;
        else if ( str[i] == '1'|| str[i] == '3' || str[i] == '5' || str[i] == '7' || str[i] == '9' )
         count++;
    }
    printf("%d\n",count);
    return 0;
}
