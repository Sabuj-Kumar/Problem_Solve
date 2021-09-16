#include<stdio.h>//nPr
#include<conio.h>
int factorial(int n)// doing factorial here
{
    int i,ans=1;
    for(i=1;i<=n;i++)
       {
        ans=ans*i;
       }
    return ans;
}

int main()// now the main nPr determination
{
    int n,r,nPr;
    scanf("%d%d",&n ,&r);
    nPr=factorial(n)/factorial(n-r);
    printf("%d", nPr);

getch();
return 0;

}
