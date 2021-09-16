#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,test = 0;

    while(scanf("%d",&n) && n != 0)
    {
        int count = 0,input;

        while(n--)
        {
            scanf("%d",&input);

            if(input == 0)
                count--;
            else
                count++;
        }
        printf("Case %d: %d\n",++test,count);
    }
    return 0;
}
