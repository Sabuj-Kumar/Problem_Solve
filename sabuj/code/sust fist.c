#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    int i;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
            continue;
        else
        printf("%c",a[i]);
    }

}
