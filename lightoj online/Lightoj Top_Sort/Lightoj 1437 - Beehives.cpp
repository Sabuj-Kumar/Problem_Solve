#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
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

const int N = 510;
vector< int > graph[ N ];
int ans;

void Small_Cycle(int n){

    ans = INT_MAX;

    for(int i = 0; i < n; i++){

        vector< int > pa(n,-1);
        vector< int > dis(n,INT_MAX);
        queue< int > q;

        q.push( i );
        dis[ i ] = 0;

        while(!q.empty()){

            int u = q.front();

            q.pop();

            for(auto x : graph[ u ]){

                if(dis[ x ] == INT_MAX){

                    dis[ x ] = dis[ u ] + 1;
                    pa[ x ] = u;
                    q.push( x );
                }
                else if(pa[ u ] != x) ans = min(ans,(dis[ x ] + dis[ u ] + 1));
            }
        }
    }
}
int main(){

    file();

    int t;

    cin >> t;

    Case( t ){

        for(int i = 0; i < N; i++) graph[ i ].clear();

        int n,m;

        cin >> n >> m;

        while(m--){

            int a,b;

            cin >> a >> b;

            graph[ a ].pb( b );
            graph[ b ].pb( a );
        }

        Small_Cycle( n );

        cout << "Case " << cs <<": ";

        if(ans == INT_MAX) cout << "impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}
