#include<stdio.h>
#define pf printf
#define sf scanf
int main()
{
    int n,i,cheak=0;
    pf("Enter The Value Of N :  ");
    sf("%d",&n);
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cheak=1;
        }
    }
    if(cheak==0)
        pf("\nN Is Prime.\n");
    else
        pf("\nN Is Not Prime.\n");
    return 0;
}
