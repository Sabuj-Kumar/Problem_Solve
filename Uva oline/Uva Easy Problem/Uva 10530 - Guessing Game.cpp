#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

#define sf scanf
#define pf printf

using namespace std;

int main()
{
    string a;
    int b,max = 11, min = -1;

    while(1)
    {
        sf("%d",&b);

        if(b == 0)
          break;

        getchar();

        getline(cin,a);

        if(a == "too high")
        {
            if(max > b)
              max = b;
        }
        else if(a == "too low")
        {
            if( min < b)
              min = b;
        }
        else
        {
            if( b > min && b < max)
              pf("Stan may be honest\n");

            else
              pf("Stan is dishonest\n");

            min = -1;
            max = 11;
        }
    }
    return 0;
}
