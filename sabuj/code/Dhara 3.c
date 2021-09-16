#include<stdio.h>
int main()
{
    int value,n,a=1,d;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);
    printf("\nEnter The Value of D : ");
    scanf("%d",&d);

    value= a+(n-1)*d;
    printf("\nPosition Value Is = %d\n",value);


    return 0;
}
