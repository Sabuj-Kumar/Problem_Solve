#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int input;

    int n,i = 0;

    scanf("%d",&n);

    scanf("%d",&input);

    while( 1 )
    {
        if( input % 4 == 0 || input % 400 == 0 &&  input % 100 != 0)
        {
            printf("%d  ",input);
            i++;
        }
        input++;

        if( i == n )
         break;
    }
    printf("\n");

    return 0;
}
