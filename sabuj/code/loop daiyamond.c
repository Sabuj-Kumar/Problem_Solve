#include<stdio.h>
int main()
{
    int i,j,k,n;

    printf("Enter The Diamond Size : ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        }
       for(k=2;k<=2*i;k++)
        {
            printf("*");
        }
        printf("\n");
    }

    for(i=0;i<=n;i++)
    {
        for(j=n;j>=n-i;j--)
        {
            printf(" ");
        }
       for(k=2*n-2;k>2*i+1;k--)
        {
            printf("*");
        }
        printf("\n");
    }
}
