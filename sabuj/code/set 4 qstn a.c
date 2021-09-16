#include<stdio.h>
#include<string.h>
int main()
{
    char s1[100],s2[100];
    int i;
    strcpy(s2,strcpy(s2,"JOHN SNOW"));
    strcpy(s1,"YOU KNOW ");///there is a space after KNOW.
    for(i=0;i<2;i++)
        strcat(s1,"NOTHING ");///there is a space after NOTHING.
    printf("%d\n",strlen(s1));
    printf("%d\n",strlen(s2));
    printf("%s\n",s1);
    printf("%s\n",s2);
    return 0;

}
