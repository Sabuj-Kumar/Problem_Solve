#include<stdio.h>
float pi=3.14159;
int main()
{
    float sum=0,r,square,circle;
    scanf("%f",&r);
    square=r*r;
    circle=pi*square;
    sum=square-(r+r);
    printf("%f",sum);

}
