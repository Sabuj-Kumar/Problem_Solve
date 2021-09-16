#include<stdio.h>
int main()
{
    char s1[100],s2[100];
    int i,j,ln;
    printf("Enter The First String : ");
    scanf("%s",s1);
    printf("Enter The Second String : ");
    scanf("%s",s2);
    for(i=0; s1[i]!='\0'; i++)
    {
        ln=i;
    }
    ln++;
    printf("%d\n",ln);
    for(j=0; s2[j]!='\0'; j++)
    {
        s1[ln++]=s2[j];
    }
    s1[ln]='\0';
    printf("Adding String Is = %s",s1);

    return 0;
}
