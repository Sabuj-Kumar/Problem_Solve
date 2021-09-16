#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char a[1100];

    while(gets(a))
    {
        int i = 0,j = 0,k = 0,flag = 1,len = 0;
        char b[1100],c[1100];

        if(strcmp(a,"DONE") == 0)
            break;

        for(len = 0; a[len] != '\0'; len++);

        for(i = 0; i < len; i++)
        {
            if((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z'))
            {
                if(a[i] >= 'A' && a[i] <= 'Z')
                    a[i] += 32;

                b[j] = a[i];
                j++;
            }
        }
        b[j] = '\0';

        for(i = --j; i >= 0; i--)
        {
           c[k] = b[i];
           k++;
        }
        for(i = 0; i <= j; i++)
        {
            if(b[i] != c[i])
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
          printf("You won't be eaten!\n");

        else
          printf("Uh oh..\n");
    }
    return 0;
}
