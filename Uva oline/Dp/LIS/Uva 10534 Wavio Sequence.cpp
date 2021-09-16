#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define f first
#define s second
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::syn_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator <(const data &a) const{

        return x < a.x;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int I(){ int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return n; }

vector< int > v;
int n;
vector< int > LIS(vector< int > &v){

    vector< int > v1( v.size() ),temp;

    for(int i = 0; i < v.size(); i++){

        auto it = lower_bound(temp.begin(),temp.end(),v[ i ]);

        if(it == temp.end()) temp.pb( v[ i ] );
        else *it = v[ i ];
        v1[ i ] = temp.size();
    }

    return v1;
}

int main(){

    file();

    while(cin >> n){

        v.clear();

        for(int i = 0; i < n; i++) v.pb( I() );


        vector< int > lis = LIS( v );
        reverse(v.begin(),v.end());
        vector< int > lds = LIS( v );
        reverse(lds.begin(),lds.end());

        int ans = 0;

        for(int i = 0; i < n; i++) ans = max(ans,min(lis[ i ] - 1,lds[ i ] - 1));

        cout << ans * 2 + 1 << endl;

    }
    return 0;
}

