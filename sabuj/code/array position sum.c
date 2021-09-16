#include<stdio.h>
int main()
{
    int a[100],i,sum=0,p,n,q;
    printf("Enter The Array Size : ");
    scanf("%d",&n);
    printf("\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1)
    {

        printf("\nEnter Lower Position : ");
        scanf("%d",&p);
        printf("\n");
        printf("Enter Upper Position : ");
        scanf("%d",&q);

        for(i=p; i<=q; i++)
        {
            sum+=a[i];
        }
        printf("\nThe sum is = %d\n",sum);
    }
}


