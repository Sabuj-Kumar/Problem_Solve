#include<stdio.h>
int main()
{
    char s[10000];
    int i,j,cs,ln=0;
    scanf("%d",&cs);
    for(i=0;i<cs;i++)
    {
        scanf("%s",s);
        for(j=0; s[j]!='\0'; j++)
        ln++;
        if(ln>10)
        printf("%c%d%c\n",s[0],(ln-2),s[ln-1]);
        else
        printf("%s\n",s);
        ln=0;
    }
    return 0;

}
