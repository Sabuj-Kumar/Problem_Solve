#include<bits/stdc++.h>
#define pi cos(-1)
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
#define op ios_base::sync_with_stdin(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 1e6;
const int inf = 1e9;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ N + 10 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator <(const data &a) const{

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
    return ( (n % m) * x ) % m;
}
void seive(){

    memset(prime,true,sizeof prime);
    prime[ 0 ] = prime[ 1 ] = false;

    for(int i = 2; i < N; i++)
        if(prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = false;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

struct node{

    node *next[ 2 ];

    node(){

        next[ 0 ] = nullptr;
        next[ 1 ] = nullptr;
    }
}*root;

ll n,mx,mn;
vector< ll > v;

void Insert(ll val){

    node *temp = root;

    for(int i = 31; i >= 0; i--){

        int idx = (val >> i) & 1;

        if(temp->next[ idx ] == nullptr) temp->next[ idx ] = new node();

        temp = temp->next[ idx ];
    }
}

ll query_max(ll val){

    node *temp = root;
    ll a = 0;

    for(int i = 31; i >= 0; i--){

        int x = (val >> i) & 1;

        if(temp->next[ !x ] != nullptr) {

            a |= (1 << i);

            temp = temp->next[ !x ];
        }
        else temp = temp->next[ x ];
    }

    return a;
}

ll query_min(ll val){

    node *temp = root;
    ll a = 0;

    for(int i = 31; i >= 0; i--){

        int x = (val >> i) & 1;

        if(temp->next[ x ] == nullptr) {

            a |= (1 << i);

            temp = temp->next[ !x ];
        }
        else temp = temp->next[ x ];
    }

    return a;
}

void Delete(node *temp){

    for(int i = 0; i < 2; i++) if(temp->next[ i ] != nullptr) Delete(temp->next[ i ]);

    delete(temp);
}
int main(){

    file();

    int t = I();

    Case( t ){

        n = Il();

        ll a,xr = 0;
        mx = -1,mn = INT_MAX;

        root = new node();
        Insert( 0 );

        lop(i,0,n){

            a = Il();

            xr ^= a;

            mx = max(mx,query_max(xr));
            mn = min(mn,query_min(xr));

            Insert( xr );
        }

        printf("Case %d: %lld %lld\n",cs,mx,mn);

        Delete(root);
    }

    return 0;
}

