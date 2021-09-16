#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],i,len=0;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
      len++;
    }
    printf("%d",len);

    return 0;
}
