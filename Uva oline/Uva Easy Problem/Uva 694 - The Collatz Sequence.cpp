#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long initial = 0,limit = 0,i = 0;

    while(scanf("%lld %lld",&initial,&limit) && (initial > 0 && limit > 0))
    {
        long long count = 1,start = initial;

        while(initial != 1)
        {
            if(initial % 2 == 0)
               initial /= 2;

            else
               initial = 3 * initial + 1;

            if(initial <= limit)
              count++;

            else
                break;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++i,start,limit,count);
    }
    return 0;
}
