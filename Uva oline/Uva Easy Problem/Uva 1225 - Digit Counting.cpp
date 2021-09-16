#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int t;

    scanf("%d",&t);

    while(t--)
    {
        int input, a[22] = {0},b[10] = {0},p = 0,mod = 0;

        scanf("%d",&input);

//        if( input >= 10 )
//          for(int i = 10; i <= input; i++ )
//            a[i] = i;

        for(int i = 1; i <= input; i++)
        {
           if( i < 10 )
             b[i]++;

           else
           {
               p = i;

               while( i  > 0 )
               {
                  mod = i % 10;
                  i /= 10;
                  b[mod]++;
               }
               i = p;
           }
        }

        for(int i = 0; i <= 9; i++ )
        {
            printf("%d",b[i]);

            if( i < 9)
              printf(" ");
        }


       printf("\n");
    }

}
