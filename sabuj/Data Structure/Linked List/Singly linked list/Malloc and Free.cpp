#include<stdio.h>
#include<iostream>
#include<stdlib.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    int *ptr,num = 0,input = 0,sum = 0;

    pf("Enter The Number Of Element.   ");
    sf("%d",&num);

    ptr = (int*)malloc(num * sizeof(int));

    if( ptr == NULL)
    {
        pf("Hudai kisoi nai\n");

        exit(0);
    }

    pf(" \nEnter The Element's Of Array..\n\n");

    for(int i = 0; i < num; i++ )
    {
        sf("%d",ptr+i);

        sum += *ptr+i;
    }
    pf("sum = %d\n",sum);

    for(int i = 0; i < num; i++ )
    {
        pf("%d ",*ptr);
        ptr++;
    }
    pf("\n\n");

    pf("%d\n",(int*)malloc(num * sizeof(int)));

    free(ptr);

    for(int i = 0; i < num; i++ )
    {
        pf("%d ",*ptr);
        ptr++;
    }
    pf("\n");
    return 0;
}
