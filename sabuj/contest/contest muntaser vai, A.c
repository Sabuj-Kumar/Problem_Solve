#include<stdio.h>
int main()
{
    long long a,b,swap=0,dif=0;
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a<b)
        {
          /*swap=a;
          a=b;
          b=swap;*/
          dif=b-a;
          printf("%lld\n",dif);
        }
        else
        {
            dif=a-b;
            printf("%lld\n",dif);
        }

    }
    return 0;
}
