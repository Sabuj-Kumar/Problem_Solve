#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],s1[1000];
    int i=0,j=0,swap=0;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!='+')
        {
            s1[j]=s[i];
            j++;
        }
    }
    s1[j]='\0';
   /// puts(s1);
   for(i=0;s1[i]!='\0';i++)
   {
       for(j=0;s1[j]!='\0';j++)
       {
         if(s1[i]<s1[j])
           {
             swap=s1[i];
             s1[i]=s1[j];
             s1[j]=swap;
           }
       }
   }
   s1[i]='\0';
   ///puts(s1);
   j=0;
   for(i=0;s[i]!='\0';i++)
   {
       if(i%2==0)
       {
           s[i]=s1[j];
           j++;
       }
       else
        s[i]='+';
   }
   s[i]='\0';
   puts(s);

   return 0;
}
