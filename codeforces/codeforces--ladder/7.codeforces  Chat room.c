#include<stdio.h>
int main()
{
    char input_hallo[101],fixed_hello[]={"hello"};
    int i,j=0,count=0,flag=0;
    scanf("%s",input_hallo);
    for(i=0;input_hallo[i]!='\0';i++)
    {
      if(input_hallo[i]==fixed_hello[j])
        {
          count++;
          j++;
          if(count==5)
          {
           flag=1;
           break;
          }
        }
    }
    if(flag==1)
    printf("YES\n");
    else
    printf("NO\n");
}
