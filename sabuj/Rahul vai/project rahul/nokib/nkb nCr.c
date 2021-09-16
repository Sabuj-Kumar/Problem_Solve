#include<stdio.h>//nCr
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

int main()// now the main nCr determination
{
    int n,r,nCr;
    printf("enter n r");
    scanf("%d%d",&n ,&r);
    nCr=factorial(n)/(factorial(n-r)*factorial(r));
    printf("%d", nCr);

getch();
return 0;

}
