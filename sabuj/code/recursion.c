#include<stdio.h>
int f91(int n)
{
    if( n <= 100)
    return f91(f91(n + 11));
    else
    return n-10;
}

int main()
{
    int n,fun;

    while( scanf("%d",&n) && n != 0 )
    {
      fun = f91(n);
      printf("f91(%d) = %d\n",n,fun);
    }

}
