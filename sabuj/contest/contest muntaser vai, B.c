#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        if(a>10)
        {
            b=a-10;
            c=10;
            printf("%d %d\n",b,c);
        }
        else
        {
            b=0;
            printf("%d %d\n",b,a);
        }
    }
    return 0;
}

