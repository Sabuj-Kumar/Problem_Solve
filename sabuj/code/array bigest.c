#include<stdio.h>
int main()
{
    int i,j,k,n,ary[6],max=0,max2=0,flage=0,store=0;
    printf("Enter The Array Size : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&ary[i]);
    }
    max=ary[0];
    max2=ary[0];

    for(i=1;i<=n;i++)
    {

      if(max<ary[i])
       {
          max=ary[i];

          flage=1;

          if(flage==1)
           {
             store=i;
           }
       }

       /*if(max>max2)
       {
           if(max2<ary[i])
           {
             max2=ary[i];
           }
       }*/
    }
    printf("Position Of I Is = %d\n\n",store+1);
    printf("Hight Number Is = %d\n\n",max);
    //5printf("Second Hight Number Is = %d\n",max2);
    //printf("Second Hight Number Is = %d\n",max2);

}

