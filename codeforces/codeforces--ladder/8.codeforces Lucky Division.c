#include<stdio.h>
int main()
{
    int mod=0,div=0,n,a[1001],i=0,flag=0;
    scanf("%d",&n);
    if(n%4==0 || n%7==0 || n%47==0 || n%744==0)
    printf("YES\n");
    else
    {
       for(i=0;n>0;i++)
       {
          a[i]=n%10;
          n/=10;
          if(a[i]==4 || a[i]==7)
          flag=1;
          else
          {
              flag=0;
              break;
          }
       }
       if(flag==1)
       printf("YES\n");
       else
       printf("NO\n");
    }
    return 0;
}
