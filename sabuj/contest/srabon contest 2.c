#include<stdio.h>
int main()
{
    int m1,m2,m3,a,b,c,i,sum=0;
    scanf("%d %d %d",&m1,&m2,&m3);
    a=10*m1;
    b=10*m2;
    c=10*m3;
    if(a<100)
        sum+=a;
    else
        sum+=100;

    if(b<100)
      sum+=b;
    else
      sum+=100;

    if(c<100)
      sum+=c;
    else
      sum+=100;

    printf("%d",sum);

return 0;
}
