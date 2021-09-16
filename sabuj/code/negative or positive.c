#include<stdio.h>
int main()
{
    int Digit;

    printf("Enter The Digit : ");
    scanf("%d",&Digit);

    if (Digit>0)
    {
        printf("\n'The Number Is Positive.' \n");
    }
    else if(Digit<0)
    {
        printf("\n'The Number Is Negative.' \n");
    }
    else
    {
        printf("\n'%d' 'Is Neither Positive And Neither Negative.'\n ",Digit);
    }


    return 0;
}
