#include<stdio.h>
int main()
{
    int i,n,sum=0, power=0;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d^%d",i,i);
        if(i<n)
        {
            printf("+");
        }
        power+=pow(i,i);
    }
    printf("\n\nThe Sum Of Own Power Is = %d\n",power);


}
