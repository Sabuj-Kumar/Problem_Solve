#include<stdio.h>
int recursion(int a,int *b,int c)
{
    if(a==c)
     return 0;
    else
    {
        if(b[a]%2==0)
        {
            printf("%d ",b[a]);
            recursion(a+1,b,c);
        }
        else
         recursion(a+1,b,c);
    }
}
int main()
{
    int i,n,a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    recursion(0,a,n);
    return 0;
}
