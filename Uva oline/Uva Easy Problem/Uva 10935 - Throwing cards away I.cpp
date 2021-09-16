#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int input;

    while(scanf("%d",&input) && input != 0)
    {
        int i;
        deque<int> dq;

        for(i = 1; i <= input; i++)
            dq.push_back(i);

        printf("Discarded cards:");

        while(dq.size() > 1)
        {
            printf(" %d",dq.front());

            if(dq.size() > 2)
               printf(",");

            dq.pop_front();
            dq.push_back(dq.front());
            dq.pop_front();
        }
        printf("\nRemaining card: %d\n",dq.front());
    }
    return 0;
}
