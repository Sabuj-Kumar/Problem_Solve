#include<stdio.h>
int main()
{
    int i,n,a,b,mul=0,result=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        mul=a*b;
        if(a<3||b<3)
        {
          if(a==1||b==1)
          {
              if(a>b)
                printf("Case %d: %d\n",i,a);
              else
                printf("Case %d: %d\n",i,b);
          }
          else if(a==2 || b==2)
          {
              if(a==2)
              {
                  if(b%4==1||b%4==3)
                    printf("Case %d: %d\n",i,b+1);
                  else if(b%4==2)
                    printf("Case %d: %d\n",i,b+2);
                  else
                    printf("Case %d: %d\n",i,b);
              }
              else if(b==2)
              {
                  if(a%4==1||a%4==3)
                    printf("Case %d: %d\n",i,a+1);
                  else if(a%4==2)
                    printf("Case %d: %d\n",i,a+2);
                  else
                    printf("Case %d: %d\n",i,a);
              }
          }
        }
        else if(mul%2==0)
        {
            result=mul/2;
            printf("Case %d: %d\n",i,result);
        }
        else
        {
            result=(mul/2)+1;
            printf("Case %d: %d\n",i,result);
        }

    }
  return 0;
}
