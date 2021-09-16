#include<stdio.h>
int main()
{
    printf("\t\t\t\t\t ....Welcome To The Triangle Calculation's....\n\n\n");
    int a,b,c;
    printf("Enter the values a, b and c : \n\n");
    scanf("%d%d%d",&a,&b,&c);
    /*Triangle's validity*/
    if (a>b)
    {
        if (a>c)
        {
            if (a<b+c)
            {
                printf("\nThe Triangle is valid\n");
                /*For valid we will find out the rest*/
                /* Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                if (a==b)
                {
                    if (a==c)
                        printf("\nThe triangle is an Equilateral triangle\n");
                    else
                        printf("\nThe triangle is an Isosceles triangle\n");
                }
                else
                {
                    if (a==c)
                        printf("\nThe triangle is an Isosceles triangle\n");
                    else
                    {
                        if (b==c)
                            printf("\nThe triangle is an Isosceles triangle");
                        else
                            printf("\nThe triangle is a Zodiacal triangle\n");
                    }
                }
                /*Proving If the triangle is a Right angle triangle*/
                if (a>b)
                {
                    if (a>c)
                    {
                        if ((a*a)==(b*b)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                else
                {
                    if (b>c)
                    {
                        if ((b*b)==(a*a)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                /*ends here*/
            }
            else
                printf("\nThe Triangle is invalid\n");
        }
        else
        {
            if (c<a+b)
            {
                printf("\nThe Triangle is valid\n");
                /*For valid we will find out the rest*/
                {
                    /* Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                    if (a==b)
                    {
                        if (a==c)
                            printf("\nThe triangle is an Equilateral triangle\n");
                        else
                            printf("\nThe triangle is an Isosceles triangle\n");
                    }
                    else
                    {
                        if (a==c)
                            printf("\nThe triangle is an Isosceles triangle\n");
                        else
                        {
                            if (b==c)
                                printf("\nThe triangle is an Isosceles triangle\n");
                            else
                                printf("\nThe triangle is a Zodiacal triangle\n");
                        }

                    }
                }
                /*Proving If the triangle is a Right angle triangle*/
                if (a>b)
                {
                    if (a>c)
                    {
                        if ((a*a)==(b*b)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                else
                {
                    if (b>c)
                    {
                        if ((b*b)==(a*a)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                /*Ends here*/
            }
            else
                printf("\nThe Triangle is invalid\n");
        }

    }
    else
    {
        if (b>c)
        {
            if (b<a+c)
            {
                printf("\nThe Triangle is valid\n");
                /*For valid we will find out the rest*/
                {
                    /* Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                    if (a==b)
                    {
                        if (a==c)
                            printf("\n The triangle is an Equilateral triangle\n");
                        else
                            printf("\n The triangle is an Isosceles triangle\n");
                    }
                    else
                    {
                        if (a==c)
                            printf("\nThe triangle is an Isosceles triangle\n");
                        else
                        {
                            if (b==c)
                                printf("\nThe triangle is an Isosceles triangle\n");
                            else
                                printf("\nThe triangle is a Zodiacal triangle\n");
                        }
                    }
                }
                /*Proving If the triangle is a Right angle triangle*/
                if (a>b)
                {
                    if (a>c)
                    {
                        if ((a*a)==(b*b)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                else
                {
                    if (b>c)
                    {
                        if ((b*b)==(a*a)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                /*Ends here*/
            }
            else
                printf("\nThe Triangle is invalid\n");
        }
        else
        {
            if (c<a+b)
            {
                printf("\nThe Triangle is valid\n");
                /*For valid we will find out the rest*/
                /* Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                if (a==b)
                {
                    if (a==c)
                        printf("\nThe triangle is an Equilateral triangle\n");
                    else
                        printf("\nThe triangle is an Isosceles triangle\n");
                }
                else
                {
                    if (a==c)
                        printf("\nThe triangle is an Isosceles triangle\n");
                    else
                    {
                        if (b==c)
                            printf("\nThe triangle is an Isosceles triangle\n");
                        else
                            printf("\nThe triangle is a Zodiacal triangle\n");
                    }
                }
                /*Proving If the triangle is a Right angle triangle*/
                if (a>b)
                {
                    if (a>c)
                    {
                        if ((a*a)==(b*b)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                else
                {
                    if (b>c)
                    {
                        if ((b*b)==(a*a)+(c*c))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                    else
                    {
                        if ((c*c)==(a*a)+(b*b))
                            printf("\nThe Triangle is a Right angle triangle\n");
                        else
                            printf("\nThe Triangle is not a Right angle triangle\n");
                    }
                }
                    /*Ends here*/
            }
            else
                printf("\nThe Triangle is invalid\n");
        }
    }
    return 0;
}
