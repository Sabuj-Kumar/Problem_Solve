#include<stdio.h>
#include<string.h>
int main()
{
    char input_1[1001],input_2[1001],sub[1001];
   long long  i,j,minus = 0;
    while( scanf("%s %s",input_1,input_2) )
    {
        int len_1 = strlen(input_1);
        int len_2 = strlen(input_2);
        strrev(input_1);
        strrev(input_2);

        /*for( i = 0; i < len_1; i++ )
            input_1[ i ] -= 48;

        for( i = 0; i < len_2; i++ )
            input_2[ i ] -= 48; */
        if( len_1 >= len_2 )
           for( i = 0; i < len_2; i++ )
               minus = (input_1[ i ] - input_2[ i ]) + 48;
       else
           for( i = 0; i < len_1; i++ )
               minus = (input_2[ i ] - input_1[ i ]) + 48;
       sub[ i ] = '\0';
         printf("%s\n",sub);
    }
    return 0;
}
