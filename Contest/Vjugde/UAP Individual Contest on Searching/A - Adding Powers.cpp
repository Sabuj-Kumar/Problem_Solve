#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull usingned long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define f first
#define s second
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


struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y, this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }

    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,-2,2};

int I() { int n; sc( n ); return n; }
ll Il() { ll n;  sl( n ); return n; }
vector< ll > vec;
ll n,k;

bool check(){

    vector< int > v( 100 );
    fill(v.begin(),v.end(),0);

    int mx = 0;

    for(int i = 0; i < vec.size(); i++){

        ll x = vec[ i ];
        int j = 0;

        while( x != 0 ){

           v[ j++ ] += x % k;
           x /= k;
        }

        mx = max(j,mx);
    }

    for(int i = 0; i < mx; i++) if(v[ i ] > 1) return false;

    return true;
}
int main(){

    file();

    int t = I();

    while( t-- ){

        n = Il(),k = Il();
        vec.clear();

        while( n-- ) vec.pb( Il() );

        if(check()) cout << "YES";
        else cout << "NO";
        cout << endl;
    }

    return 0;
}
