#include<stdio.h>
int main()
{
    int flage=0,i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=n; i<=m; i++)
    {
        flage=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flage=1;
                break;
            }
        }
        if(flage==1)
        {
            printf("%d",i);
            if(i<m)
                printf(",");
        }

    }


}
