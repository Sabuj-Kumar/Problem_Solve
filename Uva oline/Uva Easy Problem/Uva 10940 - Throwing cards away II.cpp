#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d",&n) && n != 0)
    {
        deque<int> dq;
        int i;

        for(i = 1; i <= n; i++)
            dq.push_back(i);

        while(dq.size() > 1)
        {
           dq.pop_front();
           dq.push_back(dq.front());
           dq.pop_front();
        }
        printf("%d\n",dq.front());
    }
    return 0;
}
