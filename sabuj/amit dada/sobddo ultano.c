#include<stdio.h>
#include<string.h>
int main()
{
    int rang,test;
    scanf("%d",&rang);
    getchar();
    for(test=0;test<rang;test++)
    {
     char str[1000],str2[1000];
     gets(str);
     strrev(str);
     int i=0,j=0;
     for(i=0;str[i]!='\0';i++)
     {
      if(str[i]==' ')
      {
        str2[j]='\0';
        strrev(str2);
        printf("%s %c",str2,str[i]);
        j=0;
      }
      else
      {
       str2[j]=str[i];
        j++;
      }
     }
     str2[j]='\0';
     printf("%s",strrev(str2));
     printf("\n");
    }
    return 0;
}
