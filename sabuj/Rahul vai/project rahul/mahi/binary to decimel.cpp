#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{
	
    int i,n,sum=0,remainder;
    scanf("%d",&n);

    for(i=0;n!=0;)
    {
    remainder = n % 10;
    n=n/10;
    sum = sum + remainder * pow(2,i);
    i++;
    }

    printf("%d",sum);
    
    getch();
    return 0 ;
}
