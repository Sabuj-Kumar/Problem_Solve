#include<stdio.h>
#include<string.h>
int main()
{
    char str[1000000];
    int count = 0,i;

    gets(str);

    for( i = 0; ; i++ )
    {
       if( str[i] == ' ' || str[i] == '\0' )
         if( str[i+1] != ' ' )
            count++;

       if( str[ 0 ] == ' ' && str[i] == '\0' )
       {
              count -= 1;
              break;
       }
       if ( str[i] == '\0' )
         break;
    }
    if ( str[ 0 ] == ' ' && str[ 1 ] == '\0' )
       printf("%d\n",count-=1);

    else
       printf("%d\n",count);

    return 0;
}
