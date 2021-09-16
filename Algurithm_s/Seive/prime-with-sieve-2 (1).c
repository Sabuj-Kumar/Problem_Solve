#include<stdio.h>
#include<math.h>
int prime[10000000]={0};
int main()
{
    int i,n=1000,j,s;
//    scanf("%d",&n);

    s=sqrt(n);
    for(i=2;i<=s;i++)
    {
        if(prime[i]==0)
        {
            for(j=2;i*j<=n;j++)
                prime[i*j]=1;
        }
    }
//    for(i=2;i<=n;i++)
//    {
//        if(prime[i]==0)
//            printf("%d\t",i);
//    }
    return 0;
}

