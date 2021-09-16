#include<stdio.h>//prime number
#include<conio.h>//je number k oi number ebong 1 sara ar kisu dia vag kora jai na , takei prime number bole
int main()

{
  int n,i,nokib=0;
  scanf("%d", &n);
  for(i=2;i<n;i++)
    {
        if(n%i==0)
       {
         nokib++;
         break;
       }

    }
    if(nokib==0)
    {printf("prime");}
    else if(nokib>0)
    {printf("not prime");}
getch();
return 0;

}
