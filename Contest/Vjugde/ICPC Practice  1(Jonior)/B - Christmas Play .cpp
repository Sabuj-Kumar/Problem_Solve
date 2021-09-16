#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int test;

    scanf("%d",&test);

    while(test--)
    {
        int K,N;

        scanf("%d %d",&N,&K);

        long long hight[ N ],min1 = 1000000000,index;

        for(int i = 0; i < N; i++)
            scanf("%lld",&hight[ i ]);

        sort(hight,hight+N);

        for(int i = 0; i < N; i++)
        {
            index = i + K-1;

            if(index == N)
                break;

            if(min1 > (hight[ index ] - hight[ i ]))
                min1 =  hight[ index ] - hight[ i ];
        }
        printf("%lld\n",min1);
    }
    return 0;
}
