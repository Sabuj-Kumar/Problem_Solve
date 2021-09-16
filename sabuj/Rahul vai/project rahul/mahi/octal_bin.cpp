#include<stdio.h>
#include<conio.h>


int main()
{
    int n,i,c;
    int rem,sum=0;

    printf("\nEnetr the value in octal :");
    scanf("%o",&n);

  for(i=1;n!=0; )
    {
        rem = n%2;
        sum += rem*i;
        n = n>>1;
        i *=10;

    }
    printf("\nThe binary value is %d",sum);




    getch();
    return 0;
}
