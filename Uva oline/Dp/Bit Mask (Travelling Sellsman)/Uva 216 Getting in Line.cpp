#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int >
#define pll pair< ll,ll >
#define pdd pair< db,db >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
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
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c >a.c;
    }
};

struct bit{

    pdd a,b;
    db tk;

    bit(){}
    bit(pdd a) { this -> a = a; }
    bit(pdd a,pdd b) { this -> a = a,this -> b = b; }
    bit(pdd a,pdd b,db tk) { this -> a = a,this -> b = b,this -> tk = tk; }
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
int Y[ ] = {1,-1,0,0,-1,1,-1,1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

vector< pii > v;
int n;
db dp[ 10 ][ 1 << 10 ],cost[ 10 ][ 10 ];
bit out[ 10 ];

db foo(db x) { return (x * x); }

db length(pdd a,pdd b){

    db x1 = a.ft,y1 = a.sd;
    db x2 = b.ft,y2 = b.sd;

    return sqrt( foo(x2 - x1) + foo(y2 - y1) ) + 16.0;
}

db bit_mask(int idx,int mask){

    if(mask == (1 << n) - 1) return 0;

    if(dp[ idx ][ mask ] != -1) return dp[ idx ][ mask ];

    db ans = (db)INT_MAX;

    for(int i = 0; i < n; i++)
        if( !(mask & (1 << i)) ) ans = min(ans,cost[ idx ][ i ] + bit_mask(i,mask | (1 << i)));

    return dp[ idx ][ mask ] = ans;
}

void print(int idx,int mask){

    if(mask == (1 << n) - 1) return;

    db coto = bit_mask(idx,mask);

    for(int i = 0; i < n; i++){

        if(!(mask & (1 << i))){

            db ans = bit_mask(i,mask | (1 << i)) + cost[ idx ][ i ];

            if(ans == coto){

                cout << "Cable requirement to connect (" << v[ idx ].ft << "," << v[ idx ].sd << ") to (" << v[ i ].ft << "," << v[ i ].sd << ") is " << fixed << setprecision(2)<< cost[ idx ][ i ] << " feet." << endl;
                print(i,mask | (1 << i));
                break;
            }
        }
    }
}
int main(){

    file();

    int x,y;
    int t = 1;

    while(cin >> n){

        if( !n ) break;
        v.clear();

        lop(i,0,n) {

            cin >> x >> y;
            v.pb({x,y});
        }

        lop(i,0,n)
        lop(j,i + 1,n) {

            cost[ i ][ j ] = length(v[ i ],v[ j ]);
            cost[ j ][ i ] = cost[ i ][ j ];
        }

        db ans = (db)INT_MAX;
        int st = 0;

        for(int i = 0; i < n; i++){

           for(int j = 0; j < n; j++)
              fill(dp[ j ],dp[ j ]+(1<<10),-1);

            db val = bit_mask( i,1 << i );

            if(ans > val) ans = val,st = i;
        }

        for(int j = 0; j < n; j++)
            fill(dp[ j ],dp[ j ]+(1<<10),- 1);

        cout << "**********************************************************" << endl;
        printf("Network #%d\n",t++);
        print(st,1 << st);
        cout << "Number of feet of cable required is " << fixed <<setprecision(2)<< ans <<"." << endl;
    }

    return 0;
}
