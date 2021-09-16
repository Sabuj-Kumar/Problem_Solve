#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int main()
{
    string str;

    int N,i;

    scanf("%d",&N);

    for( i = 0; i < N; i++ )
    {
        cin>>str;

        if( str[0] == 'c' || str[0] == 'd' || str[0] == 'e' || str[0] == 'f')
        {
            if( str[1] == '1' || str[1] == '8' )
                printf("4\n");

            else if(str[1] == '2' || str[1] == '7')
                printf("6\n");

            else
                printf("8\n");
        }
        else if( str[0] == 'a' || str[0] == 'h' )
        {
            if( str[1] == '1' || str[1] == '8')
                printf("2\n");

            else if( str[1] == '2' || str[1] == '7')
                printf("3\n");

            else
                printf("4\n");
        }
        else
        {
            if( str[1] == '1' || str[1] == '8' )
                printf("3\n");

            else if( str[1] == '2' || str[1] == '7' )
                printf("4\n");

            else
                printf("6\n");
        }
    }

    return 0;
}
