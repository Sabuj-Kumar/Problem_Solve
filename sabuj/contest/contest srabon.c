#include<stdio.h>
#define pf printf
#define sc scanf
int main()
{
    int a[100],c[100],b,i,n,count=0,dis=0,dis1=0,distance=0;
    sc("%d",&n);
    for(i=0;i<n;i++)
        sc("%d",&a[i]);

    b=a[0];

    for(i=1;i<n;i++)
    {
        if(b>=a[i])
            dis=b-a[i];

        else if(a[i]>b)
            dis=a[i]-b;


        /*if(i==1)
         dis1=dis;*/


         /*else if(i>1)
         {
             if(dis1>dis)
                distance=dis1-dis;
             else
                distance=dis-dis1;
         }
         dis1=dis;*/

        /*if(distance==1 && distance==0)
            count=0;
        else
        {
            count=1;
            break;
        }*/

          b=a[i];
    }
    if(count==0)
        pf("Jolly");
    else
        pf("Not jolly");

    return 0;
}
