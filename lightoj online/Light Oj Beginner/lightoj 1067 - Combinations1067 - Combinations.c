#include<stdio.h>
int main()
{
    int i,j,n,r,t,sum,sub,Rmul,Nmul,NRmul;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        Nmul=1;
        Rmul=1;
        NRmul=1;
        sub=0;
        scanf("%d%d",&n,&r);
        sub=n-r;
        for(j=1;j<=n;j++)
        {
           Nmul*=j;
           Nmul=Nmul%1000003;
        }
        for(j=1;j<=r;j++)
        {
            Rmul*=j;
            Rmul=Rmul%1000003;
        }

        for(j=1;j<=sub;j++)
        {
          NRmul*=j;
          NRmul=NRmul%1000003;

        }
        int temp=(NRmul*Rmul)%1000003;

        printf("%d %d\n",Nmul,temp);
        sum=(Nmul/(temp))%1000003;
        printf("Case %d: %d\n",i,sum);
    }
  return 0;
}
