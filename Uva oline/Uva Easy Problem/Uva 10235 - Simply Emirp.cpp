#include<stdio.h>
#include<iostream>
#include<math.h>

#define n 1000100

int a[n];
int b[n/2];

void seive()
{
    int i = 0,j = 0,root = sqrt(n);

    for(i = 4; i < n; i += 2)
        a[i] = 1;

    for(i = 3; i <= root; i += 2)
        if(a[i] == 0)
           for(j = i*i; j < n; j += i)
             a[j] = 1;
    j = 0;

    for(i = 2; i < n; i++)
    {
        if(a[i] == 0)
        {
            b[j] = i;
            j++;
        }
    }
}
int check_prime(int input)
{
    int i = 0,flag = 0;

    for(i = 0; i < input; i++)
    {
        if(b[i] == input)
        {
            flag = 1;
            break;
        }
        else if(b[i] > input)
            break;
    }
    return flag;
}
int main()
{
    seive();
    int input;

    while(scanf("%d",&input) != EOF)
    {
        int flag = 0,input1 = 0;

        flag = check_prime(input);

        if(flag == 1)
        {
            int check = 0,mod = 0;

            check = input;

            while(check)
            {
                input1 = input1 * 10 + check % 10;
                check /= 10;
            }
            if(input == input1)
               printf("%d is prime.\n",input);

            else
            {
                flag = check_prime(input1);

                if(flag == 1)
                  printf("%d is emirp.\n",input);

                else
                  printf("%d is prime.\n",input);
            }
        }
        else
            printf("%d is not prime.\n",input);
    }
    return 0;
}
