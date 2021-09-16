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

vector< vector< ll > > dp;
vector< ll > v;

ll calculate(int l,int r){

    if(dp[ l ][ r ] != -1) return dp[ l ][ r ];

    if(l == r) return 0;

    return dp[ l ][ r ] = v[ r ] - v[ l ] + min(calculate(l , r - 1),calculate(l + 1,r));
}
int main(){

    //file();

    int n;

    cin >> n;

    vector< vector< ll > > a(n,vector< ll > (n,-1));
    swap(dp,a);

    for(int i = 0; i < n; i++){

        ll val;

        cin >> val;

        v.pb( val );
    }

    sort(v.begin(),v.end());

    cout << calculate(0,n-1) << endl;

    return 0;
}


