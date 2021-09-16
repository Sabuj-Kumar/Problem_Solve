#include<stdio.h>
#include<string.h>
long long power( long long  input,long long p )
{
    long long i,mul = 1;
    for ( i = 0; i < p; i++ )
    mul *= input;
    return mul;
}
int main()
{
    char input[100];
    while ( scanf("%s",input) )
    {
       long long i,result = 0,j = 0,check,len;
       for ( len = 0; input[len] != '\0'; len++ );

       for ( i = len - 1; i >= 0; i-- )
       {
           check = input[i] - 48;
           result += check *( power( 2,++j ) - 1 );
       }
       if( result == 0 )
          break;
       else
          printf("%lld\n",result);
    }
    return 0;
}
