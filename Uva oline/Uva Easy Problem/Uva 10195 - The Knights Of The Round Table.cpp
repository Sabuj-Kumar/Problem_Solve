#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    double a,b,c;

    while( scanf("%lf %lf %lf",&a,&b,&c) == 3 )
    {
        double s = 0,p;

        if( a == 0 || b == 0 || c == 0 )
           printf("The radius of the round table is: 0.000\n");

        else
        {
          s = ( a + b + c ) / 2.0;

          p = ((s - a)*( s - b)*(s - c))/s;

          printf("The radius of the round table is: %.3lf\n",sqrt(p));
        }
    }
    return 0;
}
