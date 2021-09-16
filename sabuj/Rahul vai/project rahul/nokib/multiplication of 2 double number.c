#include<stdio.h>   //multiplication of 2 double number
#include<conio.h>
int main()
{
    float a,b;
    float mul;
    printf("Enter two number\n");
    scanf("%f %f", &a ,&b);
    mul= a * b;
    printf("multiplication is :: %f",mul);
    getch();
    return 0;
}
