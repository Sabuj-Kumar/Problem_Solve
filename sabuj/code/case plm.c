#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter The Value Of A :  ");
    scanf("%d",&a);

    printf("\nEnter The Value Of B :  ");
    scanf("%d",&b);

    printf("\nEnter The Value Of C :  ");
    scanf("%d",&c);

    if(a>b)
    {
        if(a>c)
        {
            printf ("\nA Is Greatest.\n");

            if(b>c)
            {
                printf("\nB Is The Second Greatest. \n");
                printf("\nC Is Last  Greatest.");
            }
            else
            {
                printf("\nC Is Second Greatest.\n");
                printf("\nB Is Last Greatest.\n");
            }
        }
        else
        {
            printf("\nC Is Greatest.\n");
            printf("\nA Is Second Greatest\n");
            printf("\nB IS Last Greatest.\n");
        }
    }
    else
    {
        if(b>c)
        {
            printf ("\nB Is Greatest.\n");
            if(a>c)
            {
                printf("\nA IS Second Greatest.\n");
                printf("\nC Is Last Greatest.\n");
            }
            else
            {
                printf("\nC Is Second Greatest.\n");
                printf("\nA Is Last Greatest.\n");
            }

        }
        else
        {
            printf("\nC Is Greatest.\n");
            printf("\nB Is Second Greatest\n");
            printf("\nA IS Last Greatest.\n");
        }

    }
    return 0;
}
