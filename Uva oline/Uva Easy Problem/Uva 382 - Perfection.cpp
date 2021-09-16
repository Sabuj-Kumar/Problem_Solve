#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int input;

    printf("PERFECTION OUTPUT\n");

    while(scanf("%d",&input))
    {
        int check = input,sum = 0,i = 0;

        if(input == 0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        else
        {
            for(i = 1; i <= input/2; i++)
            {
                if(input % i == 0)
                    sum += i;
            }

            i = 0;

            while(check > 0)
            {
                check /= 10;
                i++;
            }
            if(sum == input)
            {
                if(i < 5)
                {
                    for(int j = 0; j < (5-i); j++)
                        printf(" ");
                }
                printf("%d  PERFECT\n",input);
            }
            else if(sum < input)
            {
                if(i < 5)
                {
                    for(int j = 0; j < (5-i); j++)
                        printf(" ");
                }
                printf("%d  DEFICIENT\n",input);
            }
            else if(sum > input)
            {
                if(i < 5)
                {
                    for(int j = 0; j < (5-i); j++)
                        printf(" ");
                }
                printf("%d  ABUNDANT\n",input);
            }
        }
    }
    return 0;
}
