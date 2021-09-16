#include<stdio.h>
#include<conio.h>


main()
{
    float a,b;
    scanf("%f %f",&a,&b);
    if(b == 0)
    {
        printf("Division by zero cannot possible");
    }
    else
    {
        printf("%f",a/b);
    }


    getch();
    return 0;
}
