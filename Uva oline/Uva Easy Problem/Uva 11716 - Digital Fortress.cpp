#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    char a[1][100100];
    long long test;

    scanf("%lld",&test);

    while(test--)
    {
        for(int i = 0; i < 1; i++)
           gets(a[i]);

        int length = strlen(a[i]);
        int root = sqrt(length);

        printf("%d\n",length);

        if(root * root == length)
        {
           for(int i = 0; i < root; i++)
           {
               for(int j = 0; j < root; j++)
               {
                   printf("%c")
               }
           }
        }
    }
    return 0;
}
