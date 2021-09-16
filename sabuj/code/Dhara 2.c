#include<stdio.h>
int main()
{
    int Sum,n,d,a=1,b,c;
    printf("Enter The Value Of N :  ");
    scanf("%d",&n);

    printf("\nEnter The Value Of D :  ");
    scanf("%d",&d);

    Sum=(n/2)*(2+((n-1)*d));


    printf("\nThe Sum Is = %d\n",Sum);




    return 0;
}
