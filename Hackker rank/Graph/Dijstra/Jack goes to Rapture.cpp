#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 5 * 1e5 + 10;

int n,m;
vector< pll > graph[ N ];
ll cost[ N ];

ll Dijstra(ll node){

    priority_queue< pll,vector< pll >,greater< pll > >q;

    ll temp = -1;

    cost[ node ] = 0;

    q.push(make_pair(0,node));

    while(!q.empty()){

        auto p = q.top();

        q.pop();

        for(auto x : graph[ p.sd ]){

            temp = max(cost[ p.sd ],x.ft);

            if(temp < cost[ x.sd ]){

                cost[ x.sd ] = temp;

                q.push({cost[ x.sd ],x.sd});
            }
        }
    }

    if(cost[ n ] == INT_MAX) return -1;

    return cost[ n ];
}
int main(){

    op
  //  file();

    for(int i = 0; i <= N; i++) cost[ i ] = INT_MAX;

    cin >> n >> m;
    //cout << n << " " << m << endl;

    for(int i = 0; i < m; i++){

        int a,b,c;

        cin >> a >> b >> c;
       // cout << a << " " << b <<" " << c << endl;

        graph[ a ].pb({c,b});
        graph[ b ].pb({c,a});
    }

    ll ans = Dijstra( 1 );

    if(ans == -1) cout << "NO PATH EXISTS" << endl;
    else cout << ans << endl;

    return 0;
}
