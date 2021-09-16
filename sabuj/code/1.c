#include<stdio.h>
int main()
{
    int i,count=0,a[10];
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    for(i=0;i<10;i++)
    {
        if(a[i]==1)
            count++;
    }
    printf("\n%d",count);
}
