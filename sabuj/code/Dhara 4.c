#include<stdio.h>
#include<math.h>
int main()
{
    int a,r,n,p,N_th;
    printf("Enter The N'th Value : ");
    scanf("%d",&n);
    printf("\nEnter The Value Of Fist Number Of The Series : ");
    scanf("%d",&a);
    printf("\nEnter The Ratio Number : ");
    scanf("%d",&r);

    N_th=a*((pow(r,n)-1))/(r-1);
    printf("\nThe N'th Value Is = %d\n",N_th);

    return 0;

}
