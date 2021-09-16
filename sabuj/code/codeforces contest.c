#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],s1[1000];
    int i,j,n,store=0,count=0,ln=0;
    gets(s);
    scanf("%d",&n);
    for(i=0;s[i]!='\0';i++)
        ln++;
    if(ln==n)
    {
        for(i=0;s[i]!='\0';i++)
        {
          for(j=0;s[j]!='\0';j++)
           {
             if(s[i]==s[j])
              count++;
           }
           if(count>1)
           {
            store+=--count;
           }
           count=0;
         }
       if(store!=0)
         printf("%d",store-(store/2));
    }
    else
        printf("impossible");


}
