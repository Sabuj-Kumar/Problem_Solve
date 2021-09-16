#include<stdio.h>
int main()
{
    int i,n,fec=1;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("%d",i);
        if(i<n)
        {
            printf("*");
        }
        else
        {
            printf("!");
        }
        fec=fec*i;

    }
    printf("\n\nThe Factorial Of N Is = %d\n",fec);
}
