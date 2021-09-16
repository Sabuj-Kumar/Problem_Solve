#include<stdio.h>
#include<stdlib.h>

int *add(int *a,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum=sum+*a;
        a++;
        // sum = sum+a[i];
    }
    return &sum;
}

int main()
{
    int *p,a[3]={1,2,3};
    p=a;
    printf("Value of a[0] = %d\n",*p);
    printf("Value of a[1] = %d\n",*(p+1));
    printf("Value of a[2] = %d\n",*(a+2));
    /* calling function */
    p=add(a,3);
    printf("The value of sum is = %d",*p);
    return 0;
}
