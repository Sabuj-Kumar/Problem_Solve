#include<stdio.h>
#include<string.h>
int main()
{
    char ar[100];
    int ln,i,j;
    printf("Enter The String = ");
    gets(ar);
    for(i=0;ar[i]!='\0';i++)
        ln=i;
    ln++;
    printf("\nThe String Length Is = %d\n\n",ln);
    for(i=0;i<ln;i++)
    printf("%c",ar[i]-32);


  return 0;
}
