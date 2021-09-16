#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    char s1[6]={'A','E','I','O','U'};
    int i,j,count=0;
        printf("%s\n",s1);
    gets(s);

    for(i=0; s[i]!='\0'; i++)
    {
        for(j=0; s1[j]!='\0'; j++)
        {
            if(s[i]==s1[j])
                count++;
            //printf("%d\n",count);
        }
    }
    printf("%d\n",count);

}
