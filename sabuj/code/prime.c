#include<stdio.h>
int main()
{
    int i,n,flage=0;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);

    for(i=2;i<n;i++)
    {
        if(n%i==0)
         {
            flage=1;
         }
    }
    if(flage==0)
    {
        printf("\n%d Is Prime\n",n);
    }
    else
    {
        printf("\n%d Is Not Prime\n",n);
    }

}
