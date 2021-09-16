#include<stdio.h>
#define size 5
int array[ size ];
int top = 0;

void push( int n )
{
   if(top > size)
     printf( "Stack Is Over Flow.\n\n" );

   else
   {
     array[ top ] = n;
     top ++;
   }
}

int pop()
{
  if(top <= 0)
    printf( "Stack Is Under Flow.\n\n" );

    top --;

  return array[ top ];
}

void print()
{
    int i;

    for(i = 0 ; i < top ; i++)
      printf( "%d ",array[i] );

    printf( "\n\n" );
}
int main()
{
  int n, i, input, num, a;
  while(1)
  {
      printf( "Enter The Number For Exit Press 0 :\n" );

      printf( "Enter The Number For Push Press 1 :\n" );

      printf( "Enter The Number For Pop Press 2 :\n" );

      printf( "Enter The Number For Print Press 3 :\n" );

      printf( "\n" );

      scanf( "%d",&num );

      if(num == 0)
        return 0;

      if(num == 1)
      {
          scanf( "%d",&input );
          push( input );
      }

      if(num == 2)
      {
          a = pop();

          if(top >- 1)
            printf( "%d  Has Been Popped\n\n",a );
      }

      if(num == 3)
         print();
  }

  return 0;
}
