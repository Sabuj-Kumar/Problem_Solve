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
#define in freopen("input.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        int n,m,a,b;

        cin >> n >> m >> a >> b;

        int s[ m + 5 ];

        for(int i = 0; i < m; i++) cin >> s[ i ];

        sort(s,s+m);

        int cnt = abs(a - b) - 1;

        int total;

        if(a > b) total = (n - b) - 1;
        else total = b - 2;

        int u = total - cnt;

        int ans = 0;

        for(int i = 0; i < m; i++){

            u = max(u + 1,s[ i ]);

            if(u > total) break;

            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
