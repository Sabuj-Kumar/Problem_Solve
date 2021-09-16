#include<stdio.h>
#include<iostream>

#define sf scanf
#define pf printf

using namespace std;

void add(int a,int b)/// it must be same data type function for pointer call (  void (*p) (int,int)  )
{
    pf("%d\n",a+b);
}
int main()
{
    int a,b;

    void (*p)(int,int);

///    void (*p) ( int x,int y); we can use also.
    p = &add;
/// p = add; we can use this type also.
    sf("%d",&a);
    sf("%d",&b);

    p(a,b);

    return 0;
}
