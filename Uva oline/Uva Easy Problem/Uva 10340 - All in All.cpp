#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string a,b;

    while(cin>>a>>b)
    {
        int k = -1,flag = 0;

        for(int i = 0; i < a.size(); i++)
        {
            for(int j = k+1; j < b.size(); j++)
            {
                if(a.at(i) == b.at(j))
                {
                    k = j;
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            if(flag == 0)
                break;
        }
        if(flag == 1)
          printf("Yes\n");

        else
          printf("No\n");

    }
    return 0;
}
