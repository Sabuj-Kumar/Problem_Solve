#include<stdio.h>
#include<ostream>

using namespace std;

int main()
{
    long long input1,input2,i;

    while(scanf("%lld %lld",&input1,&input2)==2)
    {
       long long count = 0;

       for( i = input1; i <= input2; i++)
       {
           if( i % 4 == 0 )
           {
              if( i % 100 == 0 && i % 400 == 0 )
              {
                  printf("%lld ",i);

                  count++;
              }
              else
                  printf("%lld ",i);

              count++;
           }
       }
       printf("\n%lld\n\n",count);
    }
    return 0;
}
