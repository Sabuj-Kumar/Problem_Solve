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
#define in freopen("in.txt","r",stdin);

using  namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

void solve(){

    int mod = 1e9+7;

    int n;

    cin >> n;

    vector< int > v(n);

    for(int i = 0; i < n; i++) cin >> v[ i ];

    int min1 = *min_element(v.begin(),v.end());

    int cnt = 0;

    for(int x : v){

        if(x == min1) cnt++;

        if((x&min1) != min1){

            cout << "0" << endl;

            return;
        }
    }

    ll fact = 1;

    for(int i = 1; i <= n - 2; i++) fact = (1LL * fact * i) % mod;

    ll ans = (1LL * cnt * (cnt - 1)) % mod;
    ans = (1LL * ans * fact) % mod;

    cout << ans << endl;
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        solve();
    }

    return 0;
}
