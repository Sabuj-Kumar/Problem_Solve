#include<stdio.h>
int main()

{
    int i,max=0,n,a[100],a2[100],count=0;
    printf("ENter The value of n : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            count++;
        }
        if(max<count)
        {
            max=count;
        }

        if(a[i]==0)
        {
            count=0;
        }


    }

    printf("%d",max);


}
