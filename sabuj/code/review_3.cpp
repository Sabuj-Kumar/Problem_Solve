#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *p;
    p=(int *)malloc(100*sizeof(p));
    printf("Value of p using malloc = %d",*p);
    free(p);

    p=(int *)calloc(100,sizeof(p));
    printf("\nValue of p using calloc = %d",*p);
    free(p);

}
