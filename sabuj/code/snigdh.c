#include<stdio.h>
int main()
{
    int a,b,c,x,y,z,result=0;
    scanf("%d %d %d %d",&a,&b,&x,&y);
    c=a*b;
    z=x*y;
    result=c+z;
    printf("%d \n",result);
    a=0;
    b=0;
    x=0;
    y=0;
    int mod1=0,mod2=0,result2=0;

    while (c>0)
    {
      mod1=(c%10);
      c=c/10;
      if(a==0)
        a=mod1;
      else
        b=mod1;
    }

    while (z>0)
     {
      mod2=z%10;
      z=z/10;
      if(x==0)
        x=mod2;
      else
        y=mod2;
    }
   result2=a+b+x+y;
   printf("%d %d %d %d\n",b,a,y,x);
   printf("%d",result2);

   if(result==result2)
    printf("\nyes");
   else
    printf("\nno");


}
