#include<stdio.h>
float   pw( float a)
{
    float i,mul = 1;
    for( i = 0; i < 2; i++ )
        mul *= a;
    return mul;
}
float fact( float a )
{
    float i,fat = 1;
    for( i = 1; i <= a; i++ )
        fat *= i;
    return fat;
}
int main()
{
    int a,i;
    float sum = 0;
    scanf("%d",&a);
    for( i = 1; i <= a; i++ )
    {
        if( i == 1 )
        {
            sum += i;
            printf("1 + ");
        }
        else
        {
            printf("%d^2/%d!",i,i);
            sum += pw(i)/fact(i);
            if( i < a )
            printf(" + ");
        }
    }
    printf("\n\n%.2f\n",sum);

    return 0;
}
