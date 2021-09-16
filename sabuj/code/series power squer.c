#include<stdio.h>
#include<math.h>
int main()
{
    int power=0,i,n;
    printf("Enter The Value Of N : ");
    scanf("%d",&n);
    printf("\n");
    for(i=1;i<=n;i++)
    {
        printf("%d^2",i);
        if(i<n)
        {
            printf("+");
        }
        power+=pow(i,2);
    }
    printf("\n\nThe Sum Of Power Is = %d\n",power);
}
