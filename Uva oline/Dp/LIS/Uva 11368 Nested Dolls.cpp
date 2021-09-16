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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){};
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
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
    return ( (n % m) * x) % m;
}

bool cmp(pii a,pii b){

    if(a.s == b.s) return a.f < b.f;
    return a.s > b.s;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -118;
const ll mod = 1e9 + 7;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int n;
vector< pii > v;

int b_search( ){

    vector< int > temp;
    int ans = 0;

    temp.push_back(INT_MAX);

    for(int i = 0; i < n; i++){

        int pos = lower_bound(temp.begin(),temp.end(),v[ i ].f + 1) - temp.begin();

        if(pos == temp.size()-1)ans++,temp.push_back(INT_MAX);

        temp[ pos ] = v[ i ].f;
    }

    return ans;
}

int main(){

    file();

    int t = I();

    while( t-- ){

        n = I();
        vector< pii > v1( n );
        swap(v,v1);

        lop(i,0,n) v[ i ] = {I(),I()};
        sort(v.begin(),v.end(),cmp);

        int ans =  b_search();

        cout << ans << endl;
    }

    return 0;
}
