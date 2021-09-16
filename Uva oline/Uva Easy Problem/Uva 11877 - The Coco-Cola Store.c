#include<stdio.h>
int main()
{
    int cola;
    while ( scanf("%d",&cola) && cola != 0 )
    {
        int cheek = 0;
        cheek = cola;
        cola = 0;
        while( cheek > 2 )
        {
            cola += cheek / 3;
            cheek = ( cheek / 3 ) + ( cheek % 3 ) ;
        }
        if ( cheek == 2 )
        cola++;
        printf("%d\n",cola);
    }
    return 0;
}
