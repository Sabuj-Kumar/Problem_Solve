#include<bits/stdc++.h>

using namespace std;

int main()
{
    double a,b,c,d,e,result = 0;

    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);

    result = (a+b)*(a+b)*(c-d)/e;

    printf("%lf\n",result);

    return 0;
}
