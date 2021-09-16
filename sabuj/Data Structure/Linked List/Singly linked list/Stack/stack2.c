#include<stdio.h>
#define size 1000
int top=0,i=0;
int array [size];
int rev_array[size];

void push(int n)
{
    array[top]=n;

    top++;
}

void pop(int n)
{
    for(i=0;i<n;i++)
    {
      top--;
      rev_array[i]=array[top];
    }
}

void rev(n)
{
    for(i=0;i<n;i++)
    {
         if(array[i]==rev_array[i])
           printf("-1 ");

         else
          printf("0 ");
    }

    printf("\n\n");
}

int main()
{
  int a,n;

  while(1)
  {
    printf("Enter The Size :  ");

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
       scanf("%d",&a);

       push(a);
    }

    pop(n);

    rev(n);
  }

 return 0;
}
