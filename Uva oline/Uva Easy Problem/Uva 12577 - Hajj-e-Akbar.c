#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],s1[5]={"Hajj"},i=1;
    while( scanf("%s",s) )
    {
       if(s[0] == '*')
        break;
       if ( strcmp (s,s1) == 0 )
        printf("Case %d: Hajj-e-Akbar\n",i);
       else
        printf("Case %d: Hajj-e-Asghar\n",i);
       i++;
    }
    return 0;
}
