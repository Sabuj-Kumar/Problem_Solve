#include<stdio.h>
int main()
{
    int n,a,i,sub=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        if(a>10)
        {
            sub=a-10;
            a=10;
            printf("%d %d\n",sub,a);
        }
        else
            printf("%d %d\n",sub,a);
        sub=0;
    }
}
