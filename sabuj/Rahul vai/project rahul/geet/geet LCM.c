#include<stdio.h>
#include<conio.h>
int gcd(int divider,int dividend)
{
    int remainder=1;
    for(;remainder!=0;)
    {
        remainder= dividend%divider;
        if(remainder!=0)
        {
            divider=remainder;
        }

    }
    return divider;
}

int main()
{
    int number1,number2;
    scanf("%d%d", &number1, &number2);
    int divider,dividend;
    if(number1>=number2)
    {
        divider=number2;
        dividend=number1;
    }
    else
    {
        divider=number1;
        dividend=number2;
    }
    int Lcm;
    Lcm=(number1*number2)/gcd(divider,dividend);
    printf("%d", Lcm);
    getch();
    return 0;
}
