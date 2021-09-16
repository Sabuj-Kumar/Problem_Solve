#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,count = 0,count1 = 0,flag = 1,cheek = 1;
    char input[ 1000 ];
    char a,z,A,Z;
    ///printf("%d %d %d %d\n",'a','z','A','Z');
    gets( input );

    int len = strlen(input);

    for ( i = 0 ; i < len ; i++ )
    {
        if( input[ i ] != ' ')
        {
            if( (input [ i ] >= 65 && input[ i ] <= 90) || (input[ i ] >= 97 && input[ i ] <= 122) )
            {
                if( cheek == 1 )
                {
                     count++;
                     cheek = 0;
                }
            }
            else
            {
                if ( flag == 1 )
                {
                    count1++;
                    flag = 0;
                }
            }
        }
        else
        {
            cheek = 1;
            flag = 1;
        }
    }
    printf("Word's = %d\nNumber's = %d\n",count,count1);
    return 0;
}
