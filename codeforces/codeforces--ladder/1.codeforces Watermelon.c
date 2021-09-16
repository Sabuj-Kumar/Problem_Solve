#include<stdio.h>
int main()
{
   int input;
   scanf("%d",&input);
   if(input!=2)
   {
    if(input%2==0)
      printf("YES\n");
    else
      printf("NO\n");
   }
   else
    printf("NO\n");

    return 0;
}
