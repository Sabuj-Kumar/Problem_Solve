#include<stdio.h>
int main()
{
    int i,n,r,store=1,store1=1,store2=1;
    scanf("%d %d",&n,&r);
    for( i = 1; i <= n; i++ )
      store *= i;
    for( i = 1; i <= r; i++ )
      store1 *= i;
    for( i = 1; i <= n-r; i++ )
      store2 *= i;
    printf("nPr Is = %d\n",store/store2);
    printf("nCr is = %d\n",store/(store1*store2));
    return 0;
}
