#include<stdio.h>
int main()
{
    int input;
    while( scanf("%d",&input) && input != 0 )
    {
        int count = 0,mod = 0,i = 0,j = 0,k = 0;
        char binary[100],binary1[100];

        while( input > 0 )
        {
            mod = input % 2;
            input /= 2;
            binary[ i ] = mod + 48;
            i++;
            if ( mod == 1 )
                count++;
        }
        while( i-- )
        {
            binary1[ k ] = binary[ i ];
            k++;
        }
        binary1[ k ] = '\0';
        printf("The parity of %s is %d (mod 2).\n",binary1,count);
    }
    return 0;
}
