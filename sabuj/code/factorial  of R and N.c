#include<stdio.h>
int main()
{
    int n,r,i,N=1,R=1,fact;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);

    printf("\n");

    printf("Enter The Value Of R : ");
    scanf("%d",&r);

    for(i=1;i<=n;i++)
    {
        N=N*i;
    }

    for(i=1;i<=r;i++)
    {
        R=R*i;
    }
    int p=1;
    for(i=1;i<=n-r;i++)
    {
        p=p*i;
    }

    printf("\n%d  %d %d",N,R,p);

     fact= N /(R*p) ;

     printf("\n\nThe Result Is = %d\n",fact);


}
