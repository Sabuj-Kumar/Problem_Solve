#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scl( n ) scanf("%I64d",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
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

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

bool vis[ N ];

void seive(){

    vis[ 0 ] = vis[ 1 ] = true;
    for(int i = 2; i < N; i++){
        if( !vis[ i ] ){
            for(int j = i + i; j < N; j += i)
                vis[ j ] = true;
        }
    }
}

bool perfect_squer(ll num){

    db sqr = sqrt( num );
    if(sqr == int(sqr)) return true;
    return false;
}
int main(){

    seive();

    file();
    int n;

    sc( n );

    Lop(i,0,n){

        ll num,c = 0;
        scl( num );
        if(num % 2 == 0) {

            if(num == 4) cout << "YES" << endl;
            else cout << "NO" << endl;
            continue;
        }

        if(perfect_squer( num ) and !vis[ int(sqrt( num )) ]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
