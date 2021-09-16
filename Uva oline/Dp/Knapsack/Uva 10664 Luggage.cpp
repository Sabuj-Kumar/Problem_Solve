#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair<ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define scl( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDHE
    in
    #endif // ONLINE_JUDHE
}

struct data{

    int x,y,c;
    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}
const int N = 3e3 + 5;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int a[ 25 ],sz,sum;
int dp[ 50 ][ N ];

int knapsack(int i,int amount){

    if(i == sz) return 0;
    if(amount == sum / 2) return 1;
    if(dp[ i ][ amount ] != -1) return dp[ i ][ amount ];

    int p = 0;
    p = p or knapsack(i+1,amount+a[i]);
    p = p or knapsack(i+1,amount);
    return dp[ i ][ amount ] = p;
}
int main(){

    file();

    int test;

    sc( test );
    getchar();

    while( test-- ){

        string s;
        getline(cin,s);
        stringstream ss( s );
        sum = 0;
        sz = 0;
        int ans = 0;
        while( ss >> a[ sz ]){

            sum += a[ sz ];
            ++sz;
        }
        if(sum % 2 == 0){

            memset(dp,-1,sizeof dp);

            ans = knapsack(0,0);

            if(ans) puts("YES");
            else puts("NO");
        }
        else puts("NO");
    }

    return 0;
}

