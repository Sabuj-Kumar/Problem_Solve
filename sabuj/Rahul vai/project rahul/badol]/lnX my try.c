#include<stdio.h>//x-x2/2+x3/3-x4/4.........
#include<conio.h>
#include<math.h>
int main()
{
    int i;
    float x,sum=0;
    scanf("%f", &x);
    for(i=1;i<=10;i++)
    {
        if(i%2==1)//odd position
        {
            sum=sum+pow(x,i)/i;
        }
        else
        {
            sum=sum-pow(x,i)/i;
        }

    }
    printf("%f", sum);


    getch();
    return 0;
}
