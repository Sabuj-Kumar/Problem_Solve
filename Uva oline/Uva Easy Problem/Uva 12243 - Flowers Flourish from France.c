#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000000];
    int i,count=1,cheak=0,ln=0;
    while(1)
    {
        gets(s);
        ln=strlen(s);
        for(i=0;i<ln;i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                s[i]=s[i]+32;
        }
        s[i]='\0';
        //printf("%s\n",s);
        cheak=s[0];
        if(cheak=='*')
           break;
        for(i=0;s[i]!='\0';i++)
        {
            if(s[i]==' ')
            {
              if(cheak==s[i+1])
                    count=1;
              else
                {
                    count=0;
                    break;
                }
            }
        }
        if(count==1)
            printf("Y\n");
        else
            printf("N\n");
        ln=0;
        count=1;
    }

  return 0;
}
