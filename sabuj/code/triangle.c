#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the values a, b and c\n");
    scanf("%d%d%d",&a,&b,&c);
    {
        /**Triangle's validity*/

            if (a>b)
            {
                if (a>c)
                {
                    if (a<b+c)
                    {
                        printf("The Triangle is valid");
                        /**For valid we will find out the rest*/
                        {
                            /** Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                            if (a==b)
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Equilateral triangle");
                                }
                                else
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                            }
                            else
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                                else
                                {
                                    if (b==c)
                                    {
                                        printf("\nThe triangle is an Isosceles triangle");
                                    }
                                    else
                                    {
                                        printf("\nThe triangle is a Zodiacal triangle");
                                    }
                                }

                            }
                        }
                        {
                            /**Proving If the triangle is a Right angle triangle*/
                            if (a>b)
                                    {
                                        if (a>c)
                                        {
                                            if ((a*a)==(b*b)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }

                                    }
                                    else
                                    {
                                        if (b>c)
                                        {
                                            if ((b*b)==(a*a)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                    }
                        }
                    /**ends here*/
                    }
                    else
                    {
                        printf("The Triangle is invalid");
                    }
                }
                else
                {
                    if (c<a+b)
                    {
                        printf("The Triangle is valid");
                        /**For valid we will find out the rest*/
                        {
                            /** Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                            if (a==b)
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Equilateral triangle");
                                }
                                else
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                            }
                            else
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                                else
                                {
                                    if (b==c)
                                    {
                                        printf("\nThe triangle is an Isosceles triangle");
                                    }
                                    else
                                    {
                                        printf("\nThe triangle is a Zodiacal triangle");
                                    }
                                }

                            }
                        }
                        {
                            /**Proving If the triangle is a Right angle triangle*/
                            if (a>b)
                                    {
                                        if (a>c)
                                        {
                                            if ((a*a)==(b*b)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }

                                    }
                                    else
                                    {
                                        if (b>c)
                                        {
                                            if ((b*b)==(a*a)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                    }
                        }
                        /**Ends here*/
                    }
                    else
                    {
                        printf("The Triangle is invalid");
                    }
                }

            }
            else
            {
                if (b>c)
                {
                    if (b<a+c)
                    {
                        printf("The Triangle is valid");
                        /**For valid we will find out the rest*/
                        {
                            /** Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                            if (a==b)
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Equilateral triangle");
                                }
                                else
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                            }
                            else
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                                else
                                {
                                    if (b==c)
                                    {
                                        printf("\nThe triangle is an Isosceles triangle");
                                    }
                                    else
                                    {
                                        printf("\nThe triangle is a Zodiacal triangle");
                                    }
                                }

                            }
                        }
                        {
                            /**Proving If the triangle is a Right angle triangle*/
                            if (a>b)
                                    {
                                        if (a>c)
                                        {
                                            if ((a*a)==(b*b)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }

                                    }
                                    else
                                    {
                                        if (b>c)
                                        {
                                            if ((b*b)==(a*a)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                    }
                        }
                        /**Ends here*/
                    }
                    else
                    {
                        printf("The Triangle is invalid");
                    }
                }
                else
                {
                    if (c<a+b)
                    {
                        printf("The Triangle is valid");
                        /**For valid we will find out the rest*/
                        {
                            /** Proving if the triangle is Equilateral, Isosceles or Zodiac triangle*/
                            if (a==b)
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Equilateral triangle");
                                }
                                else
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                            }
                            else
                            {
                                if (a==c)
                                {
                                    printf("\nThe triangle is an Isosceles triangle");
                                }
                                else
                                {
                                    if (b==c)
                                    {
                                        printf("\nThe triangle is an Isosceles triangle");
                                    }
                                    else
                                    {
                                        printf("\nThe triangle is a Zodiacal triangle");
                                    }
                                }

                            }
                        }
                        {
                            /**Proving If the triangle is a Right angle triangle*/
                            if (a>b)
                                    {
                                        if (a>c)
                                        {
                                            if ((a*a)==(b*b)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }

                                    }
                                    else
                                    {
                                        if (b>c)
                                        {
                                            if ((b*b)==(a*a)+(c*c))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                        else
                                        {
                                            if ((c*c)==(a*a)+(b*b))
                                            {
                                                printf("\nThe Triangle is a Right angle triangle");
                                            }
                                            else
                                            {
                                                printf("\nThe Triangle is not a Right angle triangle");
                                            }
                                        }
                                    }
                        }
                        /**Ends here*/
                    }
                    else
                    {
                        printf("The Triangle is invalid");
                    }
                }
            }

    }



    return 0;
}
