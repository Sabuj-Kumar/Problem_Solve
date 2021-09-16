#include<stdio.h>
int main()
{
    int i,input,a,b,sum=0;
    scanf("%d",&input);
    for(i=1;i<=input;i++)
    {
        scanf("%d%d",&a,&b);
        sum=a+b;
        printf("Case %d: %d\n",i,sum);
    }

    return 0;
}
