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

vector< data > v;
int sz,path[ 1005 ],out[ 1005 ];
int dp[ 1005 ];

int LIS(int i){

    if(dp[ i ] != -1) return dp[ i ];

    int ans = 0;

    for(int j = 0; j < i; j++){

        if(v[ j ].x < v[ i ].x and v[ j ].y > v[ i ].y) {

            int tmp = LIS( j );

            if(ans < tmp){

                ans = tmp;

                path[ i ] = j;
            }
        }
    }
    return dp[ i ] = ans + 1;
}
int main(){

    file();

    int w,iq,i = 1;
    while(cin >> w >> iq) { v.pb(data(w,iq,i)),i++; }
    sz = v.size();

    sort(v.begin(),v.end());
    //for(int i = 0; i < sz; i++) cout << v[ i ].x << " " << v[ i ].y << " " << v[ i ].c<< endl;
    memset(dp,-1,sizeof dp);
    memset(path,-1,sizeof path);

    int lis = 0,start = -1;

    for(int i = 0; i < sz; i++) {

        int tmp = LIS( i );

        if(tmp > lis){

            lis = tmp;
            start = i;
        }
    }

    cout << lis << endl;
    i = lis - 1;
    while(start != -1){

        out[ i-- ] = v[ start ].c;
        start = path[ start ];
    }
    for(int i = 0; i < lis; i++) cout << out[ i ] << endl;

    return 0;
}
