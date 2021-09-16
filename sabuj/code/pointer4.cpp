#include<string.h>
#include<stdio.h>
#include<conio.h>

void strstr(char *s1,char *s2)
{
    int match_count=0;

    for(int i=0;i<strlen(s1);i++)
    {
        for(int j=0;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j])
            {
                match_count++;
            }
            else
            {
                match_count=0;
                break;
            }
            i++;
        }
        if(match_count==strlen(s2))
        {
            printf("Position is = %d",i-strlen(s2));
            break;
        }

    }
    if(match_count!=strlen(s2))
    {
        printf("Not matched");
    }
}

int main()
{
    char s1[10],s2[10];
    gets(s1);
    gets(s2);
    strstr(s1,s2);
    return 0;
}

