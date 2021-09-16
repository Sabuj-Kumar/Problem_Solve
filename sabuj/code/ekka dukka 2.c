#include<stdio.h>
int main()
{
    long long input,i,size,mul=1;
    scanf("%lld",&size);
    for( i = 1; i <= size; i++)
    {
        scanf("%lld",&input);
        while( 1 )
        {
            if ( input % 2 == 0 )
            {
                mul *= 2;
                input = input/2;
            }
            else
              break;
        }
        if ( mul != 1 )
          printf("Case %lld: %lld %lld\n",i,input,mul);
        else
          printf("Case %lld: Impossible\n",i);
        mul=1;
    }
}
