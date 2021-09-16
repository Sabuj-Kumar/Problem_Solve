#include<stdio.h>
#include<string.h>
int main()
{
  char input_string[10000],include_string[10000];
  int i,j,len1=0,len2=0,position=0,flag=0,count=0;
  gets(input_string);
  gets(include_string);
  for(i=0;input_string[i]!='\0';i++)
  len1++;
  for(i=0;include_string[i]!='\0';i++)
  len2++;
  for(i=0;i<len1;i++)
  {
      count=0;
      position=i;
      for(j=0;j<len2;j++)
      {
          if(input_string[position]==include_string[j])
          {
              count++;
              position++;
          }
          if(count==len2)
          {
              flag=1;
          }
      }
  }
  if(flag==1)
    printf("YES\n");
  else
    printf("NO\n");

}
