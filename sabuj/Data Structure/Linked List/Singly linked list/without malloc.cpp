#include<stdio.h>
#include<iostream>
#include<stdlib.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int *ptr,**ptr1,input = -1,i = 0;

    ptr1 = &ptr;
    //ptr++;

    pf("%d %d\n",&ptr,ptr1);

    while(input != 0)
    {
        sf("%d",&input);

        pf("%d\t",i);
        *ptr = input;

        i += *ptr;

        ptr++;
    }
    pf("%d\n",i);

    return 0;
}
