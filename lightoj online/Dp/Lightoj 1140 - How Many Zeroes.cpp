/***
    University Of Asia Pacific

    Sabuj Kumar Tarofdar "Believe Yourself" "Play With Brain"

    Light oj 1140 - How Many Zeroes?
***/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll lI() { ll  n; sl( n ); return n; }

int a[30];
ll dp[30][30];

ll dfs(int pos,int sta,int lead,int limit)
{
	if(pos == -1){

		return sta;
	}
	if(!limit and !lead and dp[ pos ][ sta ] != -1) return dp[ pos ][ sta ];

	int up = limit ? a[ pos ] : 9;

	ll tmp = 0;

	for(int i = 0; i <= up; i++)
	{
        if (lead == 1 and i == 0) // preamble 0
        {
            cout << 1 << " i " << i << " value " << a[ pos ] << " lead " << lead << " limit " << limit << endl;

            tmp += dfs(pos-1,sta,lead,limit and i == up);
            cout << "temp " << tmp << endl;
        }
        else
        {
            if(i == 0){

                cout << 2 << " i " << i << " value " << a[ pos ] << " lead " << lead << " limit " << limit << endl;

                tmp += dfs(pos-1,sta+1,lead and i==0,limit&&i==up);
                cout << "temp " << tmp << endl;
            }

            else{

                cout << 3 << " i " << i << " value " << a[ pos ] << " lead " << lead << " limit " << limit << endl;
                tmp += dfs(pos-1,sta,lead and i==0,limit and i==up);
                cout << "temp " << tmp << endl;
            }
        }
	}

	if(!limit and !lead) dp[ pos ][ sta ] = tmp;

	cout << "  temp = " << tmp << endl;
	return tmp;
}

ll solve(ll x)
{
    int pos = 0;

    while(x)
    {
        a[ pos++ ] = x % 10;

        x /= 10;
    }
    return dfs(pos-1,0,true,true);
}

int main(){

    file();

    int t;

    memset(dp,-1,sizeof(dp));
    cin >> t;

    for(int i = 1; i <= t; i++){

        ll n,m;

        cin >> n >> m;

        if(n==0)
            printf ( "Case% d:% lld \n",i,solve(m) - solve(n-1) +1); // 0 is a special case
        else{

            printf("Case %d: %lld\n",i,solve(m));
           /// printf("Case %d: %lld\n",i,solve(m)-solve(n-1));
        }

    }

    return 0;
}
