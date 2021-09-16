#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    long long n;

    scanf("%lld",&n);

    while(n--)
    {
        long long a = 0,b = 0,i = 0,k = 0;
        long long store = 0,count = 0,div = 0,value = 0;

        scanf("%lld %lld",&a,&b);

        for(i = a; i <= b; i++)
        {
            if(a > 100 && b >100)
              store = sqrt(i);

            else
                store = i;

            for(k = 1; k <= store; k++)
            {
                if(i % k == 0)
                  count++;
            }
            if(count > div)
            {
                div = count;
                value = i;
            }
            count = 0;
        }
        if(a > 100 && b > 100)
          printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,value,(2*div));

        else
            printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,value,div);
    }
    return 0;
}
