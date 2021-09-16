#include<stdio.h>
#include<conio.h>
int main()
{
    int divider,dividend,remainder;
    scanf("%d%d", &divider , &dividend);
    while(remainder!=0)
    {
        remainder=dividend%divider;
        if(remainder!=0)
        {
            dividend=divider;
            divider=remainder;
        }
    }
    printf("GCD is %d", divider);
    getch();
    return 0;
}
