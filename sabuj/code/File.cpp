#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

FILE *p;

int main()
{
     char str[100],str1[100];

     gets(str);

     p = fopen("text.txt","w");
     fprintf(p,"%s",str);
     fclose(p);

     p = fopen("text.txt","r");
     fscanf(p,"%[^\n]",str1);
     fclose(p);

     printf("%s\n",str1);

     return 0;

}
