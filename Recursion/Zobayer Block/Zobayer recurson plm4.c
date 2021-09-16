#include<stdio.h>
int recursion(int a,int b)
{
  int x;
  if(a<b)
  {
      if(a==0)
        printf("1+");
     else if(a==1)
        printf("x+");
     else{
          printf("x^%d",a);
          if(a<b-1)
          printf("+");
     }

  recursion(a=a+1,b);
  }
  else
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    recursion(0,n);
    return 0;

}
