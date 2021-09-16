#include<stdio.h>
#include<stdlib.h>

int main()
{
    /* introduction to pointer */
    int *p;
    scanf("%d",p);
    printf("pointer value is = %d",*p);

    int i=10;
    p=&i; // now p has address of i
    printf("\nValue of p = %d",p);
    printf("\nAddress of i = %d",p);
    printf("\nValue of i = %d",*p);

    /* multiple pointers */
    int *a,**b,***c;
    int x=10;
    a=&x;
    b=&a;
    c=&b;
    printf("\nValue of x is = %d",*a);
    printf("\nValue of x is = %d",**b);
    printf("\nValue of x is = %d",***c);


    return 0;
}
