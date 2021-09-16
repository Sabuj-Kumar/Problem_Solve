#include<bits/stdc++.h>

using namespace std;

int n,k,test,count_ = 0;
int p[ 30 ];
char q[ 30 ];
string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void permutation(int t,int k)
{
    if(count_ == k) return;

    if(t == n)
    {
        q[ t ] = '\0';

        printf("%s\n",q);

        count_ = count_ + 1;

        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(p[ i ] == 0)
        {
            q[ t ] = s[ i ];

            p[ i ] = 1;

            permutation(t+1,k);

            p[ i ] = 0;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    scanf("%d",&test);

    for(int T = 1; T <= test; T++)
    {
        memset(p,0,sizeof(p));

        scanf("%d %d",&n,&k);

        printf("Case %d:\n",T);
        count_ = 0;

        permutation(0,k);
    }
    return 0;
}
