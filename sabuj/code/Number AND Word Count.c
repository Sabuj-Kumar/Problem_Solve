#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,word = 0,number = 0;
    char input[1000];
    gets(input);
    int len = strlen(input);
    for( i = 0; i < len; i++ )
    {
        if ( ( input[i] >= 'a' && input[i] <= 'z' ) || ( input[i] >= 'A' && input[i] <= 'Z' ) )
        {
            word++;
            j = i;
            while( 1 )
            {
                if( input[ j ] == ' ' || input[ j ] == '\0')
                {
                   i = j;
                   break;
                }
                j++;
            }
        }
        else
        {
            number++;
            j = i;
            while( 1 )
            {
                if( input[ j ] == ' ' || input[ j ] == '\0' )
                {
                    i = j;
                    break;
                }
                j++;
            }
        }
    }
    printf("Word's = %d\nNumber's = %d\n",word,number);
    return 0;
}
///0 1 2 44 53 2 are numbers

