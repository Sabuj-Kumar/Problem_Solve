#include<stdio.h>
#include<stdio.h>
int main()
{
    char str[1000],str1[1000];
    int i,j,a,b,count=0;
    gets(str);
    scanf("%s",str1);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    str[i]='\0';
    for(i=0;str1[i]!='\0';i++)
    {
        if(str1[i]>='A' && str1[i]<='Z')
            str1[i]+=32;
    }
    str1[i]='\0';
    for(i=0 ;str[i]!='\0'; i++)
    {
        a=str[i];
        b=str1[i];
        if(a==b)
            count=0;
        else if(a>b)
        {
            count=1;
            break;
        }
        else if(a<b)
        {
            count=-1;
            break;
        }
    }
    if(count==0)
        printf("%d",count);
    else if(count==1)
        printf("%d",count);
    else if(count==-1)
        printf("%d",count);

return 0;
}
