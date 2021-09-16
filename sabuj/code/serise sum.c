#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("Enter The Value oF N : ");
    scanf("%d",&n);
    printf("\n");

    for(i=1;i<=n;i++)
    {
        printf("%d",i);
        if(i<n)
        {
            printf("+");
        }
        sum+=i;
   }
    printf("\n\nThe Sum Is = %d\n",sum);
}
