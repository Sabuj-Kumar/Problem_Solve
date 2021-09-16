#include<stdio.h>
#include<iostream>

using namespace std;

void add(int *p)
{
    *p += 5;
}
int main()
{
    int a;
    scanf("%d",&a);

    add(&a);

    printf("%d\n",a);

    return 0;
}
