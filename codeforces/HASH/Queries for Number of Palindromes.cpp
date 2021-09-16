/** HASH ALL POSSIBLE PALLENDROM **/

#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc1( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scl( n ) scanf("%lld",&n)
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
    data(int x,int y) { this -> x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator <(const data &a) const {

        return c > a.c;
    }
};

const int N = 5 * 1e3 + 5;
const ll P = 31;
const ll INVP = 678791932; /// P inverse modulo M
const ll M = 1e9 + 7;
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}
ll big_mod(ll n,ll p){

    if( !p ) return 1;

    ll x = 0;

    if( !(p % 2) ){

        x = big_mod(n,p/2);
        return (x * x) % M;
    }
    x = big_mod(n,p-1);
    return ( (n % M) * x) % M;
}
string s;
ll n,sz;
ll PM[ N ],H1[ N ],H2[ N ],HASH[ N ][ N ];

void init(){

    PM[ 0 ] = 1;

    lop(i,1,N) PM[ i ] = (PM[ i - 1 ] * P) % M;
}
void hash_build(){

    sz = s.size();
    H1[ 0 ] = H2[ sz+1 ] = 0;
    for(int i = 1; i <= sz; i++) H1[ i ] = (H1[ i - 1 ] * P +  s[ i - 1 ]) % M;
    for(int i = sz; i >= 1; i--) H2[ i ] = (H2[ i + 1 ] * P +  s[ i - 1 ]) % M;
}
bool hash_value(int l,int r){

    if(l == r) return true;
    ll h1 = 0,h2 = 0;
    if(l == 1) h1 = H1[ r ];
    else h1 = H1[ r ] - (H1[ l - 1 ] * PM[ r - l + 1 ]) % M;
    if( h1 < 0) h1 += M;
    if(r == sz) h2 = H2[ l ];
    else h2 = H2[ l ] - (H2[ r + 1 ] * PM[ r - l + 1 ]) % M;
    if(h2 < 0) h2 += M;
    return h1 == h2;
}
void dp(){

    for(int i = 1; i <= sz; i++)
        for(int j = i; j <= sz; j++)
            if( hash_value(i,j) )
                HASH[ i ][ j ] = 1;
    ll v = 0;
    for(int i = 1; i <= sz; i++){
        v = 0;
        for(int j = 1; j <= sz; j++){
            v += HASH[ i ][ j ];
            HASH[ i ][ j ] = HASH[ i - 1 ][ j ] + v;
        }
    }
}
int main(){
    init();
    file();
    cin >> s;
    hash_build();
    dp();
    sc1( n );
    while( n-- ){
        int a,b;
        sc2(a,b);
        printf("%lld\n",(HASH[ b ][ b ] + HASH[ a - 1 ][ a - 1 ]) - (HASH[ b ][ a - 1 ] + HASH[ a - 1 ][ b ]) );
    }
    return 0;
}
