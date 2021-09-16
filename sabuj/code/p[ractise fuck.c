#include<stdio.h>
int main()
{
    int a,b,x,y,result,store,store1,sum=0,mod=0;
    scanf("%d %d %d %d",&a,&x,&b,&y);

    store = a * x;
    store1 = b * y;

    result = a * x + b * y;
    printf("\n%d\n",result);

    while ( store > 0 )
    {
      mod = store % 10;
      store /= 10;
      sum += mod;
    }
    while ( store1 > 0 )
    {
      mod = store1 % 10;
      store1 /= 10;
      sum += mod;
    }
    printf("\n%d\n",sum);
    if ( sum == result )
        printf("He He He You Are A Good Programmer Baby.\n");
    else
        printf("Fuck Your Self Baby He He He.\n");
    return 0;
}
