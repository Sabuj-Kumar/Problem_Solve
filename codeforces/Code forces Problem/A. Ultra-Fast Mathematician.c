#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],s1[1000],s2[1000];
    int i,j;
    scanf("%s",s);
    scanf("%s",s1);
    //printf("%s\n%s\n",s,s1);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==s1[i])
            s2[i]='0';
        else
            s2[i]='1';
    }
    s2[i]='\0';
    printf("%s",s2);

   return 0;
}
