#include<stdio.h>
int main()
{
    int m,n,store=0;
    scanf("%d%d",&n,&m);
    if(n>m)
    {
        store=n-m;
        if(store==1)
        printf("Dr. Chaz will have %d piece of chicken left over!!",store);
        else
        printf("Dr. Chaz will have %d pieces of chicken left over!",store);

    }
    else if(m>n)
    {
        store=m-n;
        if(store==1)
    }
}
