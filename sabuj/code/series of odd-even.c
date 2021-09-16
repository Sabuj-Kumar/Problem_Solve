#include<stdio.h>
int main()
{
    int i,n,sum=0,odd,even;

    printf("Enter The Value Of N : ");
    scanf("%d",&n);

    printf("\n");

    for(i=1;i<=n;i++)
    {
        printf("%d",i);
        if(i<n)
        {

          if(i%2==1)
           {
             printf("-");
           }
         else
           {
             printf("+");
           }
        }
        if(i%2==1)
        {
            odd=i;
            sum+=odd;
        }
        else
        {
            even=i;
            sum-=even;
        }
    }
    printf("\n\nThe Sum Is = %d\n",sum);
}
