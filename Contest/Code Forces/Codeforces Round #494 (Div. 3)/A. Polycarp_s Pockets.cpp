#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);

    map <int,int> mp;

    int N,input,max = 0;

    scanf("%d",&N);

    while(N--)
    {
        scanf("%d",&input);

        mp[ input ]++;

        if(mp[ input ] > max)
           max = mp[ input ];
    }
    printf("%d\n",max);

    return 0;
}
