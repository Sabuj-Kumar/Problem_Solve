#include<stdio.h>
#include<string.h>
int main()
{
    int test,number,length=0,i,j;
    scanf("%d",&number);
    getchar();
    for(test=0;test<number;test++)
    {
        char str[10000],str2[10000];
        gets(str);
        for(i=0;str[i]!='\0';i++)
        length++;
        str[i]='\0';
        j=0;
        for(i=length-1;i>=0;i--)
        {
          str2[j]=str[i];
          j++;
        }
        str2[j]='\0';
        printf("%s\n",str2);
        length=0;
    }

  return 0;
}
