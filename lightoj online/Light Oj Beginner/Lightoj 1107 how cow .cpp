#include<stdio.h>
int main()
{
    //freopen("input.txt","r",stdin);
    int x1,y1,x2,y2,x,y,n,cow,i,j;

    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&cow);
        printf("Case %d:\n",i);
        for(j=0; j<cow; j++)
        {
            scanf("%d%d",&x,&y);
            if(x1<=x && x<=x2 && y1<=y && y<=y2)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}
