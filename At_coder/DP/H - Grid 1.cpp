#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3 + 10;
string s[ N ];
int n,m,path[ N ][ N ];
int mod = 1e9 + 7;

int Way_Of_Grid(){

    for(int i = 0; i < n; i++){

        if(s[ i ][ 0 ] == '#')  break;
        else path[ i ][ 0 ] = 1;
    }

    for(int i = 0; i < m; i++){

        if(s[ 0 ][ i ] == '#')  break;
        else path[ 0 ][ i ] = 1;
    }

    for(int i = 1; i < n; i++){

        for(int j = 1; j < m; j++){

            if(s[ i ][ j ] == '#') continue;

            if(s[ i - 1 ][ j ] != '#') path[ i ][ j ] = path[ i - 1 ][ j ];
            if(s[ i ][ j - 1 ] != '#') path[ i ][ j ] = (path[ i ][ j ] + path[ i ][ j - 1 ]) % mod;
        }
    }

    return path[ n - 1 ][ m - 1 ] % mod;
}
int main(){

    file();

    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> s[ i ];

    cout << Way_Of_Grid() << endl;

    return 0;
}
