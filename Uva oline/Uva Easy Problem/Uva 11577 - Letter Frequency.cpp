#include<stdio.h>
#include<iostream>
#include<string.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    long long test,p = 0;
    char n[] = {"abcdefghijklmnopqrstuvwxyz"};

    sf("%lld",&test);
    getchar();

    while(test--)
    {
        int max = 0,a[200] = {0},i = 0,len = 0,d = 0;
        char input[220];

        gets(input);

        len = strlen(input);

        for(i = 0; i < len; i++)
        {
            if(input[i] >= 'A' && input[i] <= 'Z')
              input[i] += 32;

            if(input[i] >= 'a' && input[i] <= 'z')
               a[input[i]]++;
        }

        for(i = 0; i < 26; i++)
        {
            if(a[n[i]] > max)
              max = a[n[i]];
        }
        for(i = 0; i < 26; i++)
        {
            if(a[n[i]] == max)
              pf("%c",n[i]);
        }
        pf("\n");
    }
    return 0;
}
