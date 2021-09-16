#include<stdio.h>
#include<bits/stdc++.h>
#include<math.h>
#define n 1000010

int a[ n ];

using namespace std;

void seive()
{
    int i,j,root = sqrt(n);

    for(i = 4; i <= n; i += 2)
        a[ i ] = 1;

    for(i = 3; i <= root; i += 2)
       if(a[ i ] == 0)
         for(j = i*i; j <= n; j += i)
            a[ j ] = 1;

}
int main()
{
    seive();

    int input;

    while(scanf("%d",&input) && input)
    {
        int i,j,num1 = 0,num2 = 0;

        for(i = 3; i < input; i++)
        {
            if(a[ i ] == 0)
            {
                num2 = input -  i;

                if(a[ num2 ] == 0)
                {
                    num1 = i;
                    printf("%d = %d + %d\n",input,num1,num2);
                    break;
                }
            }
        }
    }
    return 0;
}
