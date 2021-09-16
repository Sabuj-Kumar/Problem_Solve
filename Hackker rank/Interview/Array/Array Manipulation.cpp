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
ll Il() { ll  n; sc( n ); return n;}

int main(){

    //op;
    //file();

    ll n,q;
    ll l,r,sum;

    cin >> n >> q;

    vector< ll > a(n + 10,0);

    for(int i = 0; i < q; i++){

        cin >> l >> r >> sum;

        a[ l ] += sum;

        if(r + 1 <= n) a[ r + 1 ] -= sum;
    }

    sum = 0;
    ll ans = 0;

    for(int i = 1; i <= n; i++){

        sum += a[ i ];

        ans = max(sum,ans);
    }

    cout << ans << endl;

    return 0;
}
