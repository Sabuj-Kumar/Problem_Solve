#include<stdio.h>
#include<stdlib.h>
int a[100];
int main()
{
    int i,j,k,n,m;
    int count=0,max=0,min=0,store=0,flag=0,sum=0;
    printf("Enter The Array Limit And Enter The Rand Number : ");
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        a[i]=rand()%m;
        sum+=a[i];
        printf("%d ",a[i]);
    }
    printf("\n\nTotal Sum Is : %d\n\n",sum);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==a[j])
                flag++;
        }
        if(flag==0)
            continue;
        else
            printf("%d is %d times.\n",i,flag);
        flag=0;
    }
    max=a[0];
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
            max=a[i];
        if(min>a[i])
            min=a[i];
    }
    for(i=0;i<n;i++)
    {
        if(max==a[i])
        {
            if(count==0)
            {
                j=i+1;
                printf("\n\nLarge Number Is %d And Position Is %d\n",max,j);
                count=1;
            }
        }
        if(min==a[i])
        {
            if(store==0)
            {
                k=i+1;
                printf("\n\nSmall Number Is %d And Position Is %d\n",min,k);
                store=1;
            }
        }
    }


    return 0;
}
