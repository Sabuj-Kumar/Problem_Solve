#include<stdio.h>
int main()
{
    int n,i,sum=1,div=0;
    scanf("%d",&n);
    div=n/2;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            if(i%2!=0)
                sum+=i;
        }
    }
    printf("%d",sum);

  return 0;
}
