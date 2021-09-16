#include<stdio.h>
int main()
{
    int  i,n,mp,fp,fp1=0,sum=0,exfl=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&mp,&fp);
        if(mp>fp)
        {
           exfl=mp-fp;
           fp1=mp+exfl;
           sum=(fp1*4)+19;
           printf("Case %d: %d\n",i,sum);
        }
        else
        {
           sum=(fp*4)+19;
           printf("Case %d: %d\n",i,sum);

        }
    }
    return 0;
}
