#include<stdio.h>
int main()
{
    char s[100], s1[100];
    int i,j,ln;
    printf("enter the string : ");
    scanf("%s",s);
    for(i=0; s[i]!='\0'; i++)
        ln=i;

        s[ln++]=' ';
        ln=i++;

    printf("%d",ln);

}
