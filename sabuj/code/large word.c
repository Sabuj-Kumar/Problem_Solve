#include<stdio.h>
#include<string.h>
int main()
{
  char input_string[1000],test_word[1000],large_word[1000];
  int i=0,j=0,k=0,ln=0,max=0;
  gets(input_string);
  for(i=0; input_string[i]!='\0'; i++)
  {
      if(input_string[i]==' ')
      {
         /// test_word[j]='\0';
          if(j>max)
          {
              max=j;
              for(k=0; test_word[k]!='\0'; k++)
              large_word[k]=test_word[k];
              ///large_word[k]='\0';
          }
          ln=0;
          j=0;
      }
      else
      {
          test_word[j]=input_string[i];
          j++;
      }
  }
  printf("\n");
  if(j>max)
  {
    max=j;
    for(i=0;test_word[i]!='\0';i++)
    large_word[i]=test_word[i];
  }
  large_word[i]='\0';
  printf("Large Word Is : %s",large_word);
  printf("\n\nword length is : %d\n",max);
  return 0;
}

