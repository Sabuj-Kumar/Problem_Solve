#include<stdio.h>
#include<string.h>

int main()
{
    char input[5000];

    while(gets(input))
    {
        int i = 0,k = 0,j = 0;
        char input1[5000] = {0};

        for(i = 0;; i++)
        {
            if(input[i] == ' ' || input[i] == '\0')
            {
                input1[j] = '\0';

                for(k = --j; k >= 0; k--)
                    printf("%c",input1[k]);

               if(input[i] != '\0')
                 printf(" ");

                j = 0;
            }
            else
            {
                input1[j] = input[i];
                j++;
            }
            if(input[i] == '\0')
                break;
        }
        printf("\n");
    }
    return 0;
}
