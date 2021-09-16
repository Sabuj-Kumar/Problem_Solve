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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 3010;
string s,p,out;
int lns,lnp;

int dp[ N ][ N ];

int LCS(int i,int j){

    if(i == lns) return 0;
    if(j == lnp) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) dp[ i ][ j ] = LCS(i + 1,j + 1) + 1;
    else dp[ i ][ j ] = max(LCS(i + 1,j),LCS(i,j + 1));

    return dp[ i ][ j ];
}

void path(int i,int j){

    if(i == lns) return;
    if(j == lnp) return;

    if(s[ i ] == p[ j ]){

        out += s[ i ];

        path(i + 1,j + 1);
    }
    else if(LCS(i + 1,j) > LCS(i,j + 1)) path(i + 1,j);
    else path(i,j + 1);
}
int main(){

    file();

    memset(dp,-1,sizeof dp);

    cin >> s >> p;

    lns = s.size();
    lnp = p.size();

    LCS(0,0);
    path(0,0);

    cout << out << endl;

    return  0;
}
