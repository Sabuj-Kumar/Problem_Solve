#include<stdio.h>
int main()
{
    char s1[100],s2[100];
    int i,j;
    printf("Enter The String : ");
    scanf("%s",s1);
    for(i=0; s1[i]!='\0'; i++)
    {
        s2[i]=s1[i];
    }
    s2[i]='\0';
    printf("\nCopy String Is = %s\n",s2);
}
