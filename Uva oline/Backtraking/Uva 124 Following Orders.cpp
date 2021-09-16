#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);
#define mem( ar ) memset(ar,-1,sizeof ar)

using namespace std;

void file(){

    #ifndef ONLINE_JYUDGE
    in
    #endif // ONLINE_JYUDGE
}

struct data{

    int x,y,c;

    data(){}
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

ll big_mod(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big_mod(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big_mod(n,p-1,m);
    return ( (n % m) * x ) % m;
}

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int I() { int n; sc( n ); return n; }
ll Il() { ll n; sl( n ); return  n; }

char out[ 30 ];
bool vis[ 30 ];
int n,valid[ 30 ],check[ 30 ][ 30 ];

void back_track(int ind){

    if(ind == n) {

        out[ ind ] = '\0';

        puts(out);

        return;
    }

    lop(i,0,26)
        if( !vis[ i ] and valid[ i ] ){

            lop(j,0,26) if(check[ i ][ j ] == 1 and vis[ j ]) return;

            vis[ i ] = true;

            out[ ind ] = i + 'a';

            back_track(ind + 1);

            vis[ i ] = false;
        }
}
int main(){

    file();
    string ch,ch1;
    stringstream ss;
    bool f = false;

    while( getline(cin,ch) ){
           getline(cin,ch1);

        ss << ch;
        char s,s1;

        if( f ) cout << '\n';
        f = true;

        memset(vis,false,sizeof vis);
        memset(valid,0,sizeof valid);
        memset(check,0,sizeof check);

        while(ss >> s) valid[ s - 'a' ] = 1;
        ss.clear();
        n = 0;
        lop(i,0,26) n += valid[ i ];

        ss << ch1;

        while(ss >> s >> s1) check[ s - 'a' ][ s1 - 'a' ] = 1;
        ss.clear();
        back_track(0);
    }
    return 0;
}
