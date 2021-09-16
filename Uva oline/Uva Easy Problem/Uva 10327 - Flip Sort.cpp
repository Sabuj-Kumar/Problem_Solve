#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int input;

    while( scanf("%d",&input) == 1 )
    {
        int a[input] = {0},i,j,key,count = 0;

        for( i = 0; i < input; i++ )
          scanf("%d",&a[ i ]);

        for( i = 1; i < input; i++ )
        {
           key = a[i];

           j = i - 1;

           while(j >=0 && a[j] > key )
           {
               a[j+1] = a[j];
               j--;
               count++;
           }
           a[j+1] = key;
        }
        printf("Minimum exchange operations : %d\n",count);
    }

    return 0;
}
