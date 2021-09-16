#include<stdio.h>
int main()
{
    int a[1000],i,n,j,count=0,swap=0,sum=0,sum1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
           if(a[i]>a[j])
           {
              swap=a[i];
              a[i]=a[j];
              a[j]=swap;
           }
    for(i=0;i<n;i++)
    {
       sum+=a[i];
       count++;
       for(j=i+1;j<n;j++)
            sum1+=a[j];
       if(sum>sum1)
           break;
        sum1=0;
    }
    printf("%d\n",count);



 return 0;
}
