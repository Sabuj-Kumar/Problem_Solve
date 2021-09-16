#include<stdio.h>
int main()
{
    int n,i,j,array[100];
    printf("Enter The Value Of N : ");
    scanf("%d",&n);
    i =0;
    while(n>0)
    {
        array[i]=n%2;
        i++;
        n/=2;
        //printf(" %d \n",n);
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%d",array[j]);
    }
}
