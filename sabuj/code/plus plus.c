#include<stdio.h>
int main()
{
    int i=0,j=4;
    i=++j + ++j + ++j;
    printf("%d\n",i);
    printf("%d",j);
}
