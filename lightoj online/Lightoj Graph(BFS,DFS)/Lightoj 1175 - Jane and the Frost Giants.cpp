#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define f first
#define s second
#define pb push_back
#define pf push_front
#define pii pair< int , int >
#define pll pair< ll,ll >
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("input.txt","r",stdin);

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
const int inf = 1e3;
const ll mx = 1e18;
const ll mx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] ={1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int sc(){ int x; cin >> x; return x; }

int n,m;
string grid[ 210 ];
int vf[ 210 ][ 210 ];
int vj[ 210 ][ 210 ];
queue< pii > Qf,Qj;

bool check(int x,int y){

    if(x >= 0 and x < n and y >= 0 and y < m) return true;
    else return false;
}
void BFSF(){

    pii p;

    while( !Qf.empty() ){

        p = Qf.front();
        Qf.pop();

        Lop(i,0,4){

            int x = p.f + X[ i ];
            int y = p.s + Y[ i ];

            if(check( x,y ) and grid[ x ][ y ] == '.' and vf[ x ][ y ] == inf){

                vf[ x ][ y ] = vf[ p.f ][ p.s ] + 1;
                Qf.push({x,y});
            }
        }
    }
}

void BFSJ(){

    pii p;

    while( !Qj.empty() ){

        p = Qj.front();
        Qj.pop();

        Lop(i,0,4){

            int x = p.f + X[ i ];
            int y = p.s + Y[ i ];

            if(check( x,y ) and grid[ x ][ y ] == '.' and vj[ x ][ y ] == inf){

                vj[ x ][ y ] = vj[ p.f ][ p.s ] + 1;
                Qj.push({x,y});
            }
        }
    }
}
int main(){

    op
    file();

    int t = sc();

    Case( t ){

        n = sc();
        m = sc();

        lop(0,n) cin >> grid[ i ];

        Lop(i,0,n){

            Lop(j,0,m){

                vf[ i ][ j ] = inf;
                vj[ i ][ j ] = inf;

                if(grid[ i ][ j ] == 'F'){

                    vf[ i ][ j ] = 0;
                    Qf.push({i,j});
                }
                if(grid[ i ][ j ] == 'J'){

                    vj[ i ][ j ] = 0;
                    Qj.push({i,j});
                }
            }
        }

        BFSF();
        BFSJ();
        int ans = inf;

        Lop(i,0,n) { if( vf[ i ][ 0 ] > vj[ i ][ 0 ]) ans = min(ans,vj[ i ][ 0 ]); }
        Lop(i,0,n) { if( vf[ i ][ m-1 ] > vj[ i ][ m-1 ]) ans = min(ans,vj[ i ][ m-1 ]); }
        Lop(i,0,m) { if( vf[ 0 ][ i ] > vj[ 0 ][ i ]) ans = min(ans,vj[ 0 ][ i ]); }
        Lop(i,0,m) { if( vf[ n-1 ][ i ] > vj[ n-1 ][ i ]) ans = min(ans,vj[ n-1 ][ i ]); }

        cout << "Case " << cs << ": ";

        if(ans == inf) cout << "IMPOSSIBLE" << endl;
        else cout << ans + 1 << endl;
    }

    return 0;
}
