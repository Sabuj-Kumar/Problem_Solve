#include<stdio.h>
#include<string.h>
int main()
{
    char vowel[10]={'A','E','I','O','U','Y'},str[1000],str1[1000],str2[1000];
    int i,j,k=0,count=0;
    gets(str);
    for(i=0; vowel[i]!='\0'; i++)
    {
        vowel[i]+=32;
    }
    vowel[i]='\0';
    ///puts(vowel);
    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
    }
    str[i]='\0';
   /// puts(str);
   for(i=0; str[i]!='\0'; i++)
    {
       for(j=0;vowel[j]!='\0';j++)
       {
           if(str[i]==vowel[j])
            {
                count=1;
                 break;
            }
       }
       if(count==0)
       {
         str1[k]=str[i];
         k++;
       }
       count=0;
    }
    str1[k]='\0';
    ///puts(str1);
    j=0;
    for(i=0;str1[j]!='\0';i++)
    {
        if(i%2==0)
            str2[i]='.';
        else
        {
            str2[i]=str1[j];
            j++;
        }
    }
    str2[i]='\0';
    puts(str2);
    return 0;
}
