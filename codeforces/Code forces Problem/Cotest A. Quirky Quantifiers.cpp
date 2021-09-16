#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int input;

    scanf("%d",&input);

    if(input % 2 == 0)
        printf("0\n");
    else
        printf("1\n");

    return 0;
}
