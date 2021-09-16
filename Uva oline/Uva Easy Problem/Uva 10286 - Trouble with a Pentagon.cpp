#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    double s = 0;

    while(sf("%lf",&s)!=EOF)
      pf("%.10lf\n",(s*1.067395682));

    return 0;
}
