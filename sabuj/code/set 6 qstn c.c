#include<stdio.h>
int main()
{
    int a[3],i,min=0,max=0;

    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }
      max=a[0];
      min=a[0];
    for(i=0;i<3;i++)
    {
         if(a[i]<min)
        {
            min=a[i];
        }
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    printf("%d %d\n",min,max);
    for(i=0;i<3;i++)
    {
        if(a[i]>min && max>a[i])
          printf("%d\n",a[i]);
    }


}
