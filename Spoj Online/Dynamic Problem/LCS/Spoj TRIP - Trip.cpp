#include<bits/stdc++.h>
#define pi acos(-1)
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
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 86;
int dp[ N ][ N ];
int n,m,len;
string s,p;
set< string > st;
unordered_map< string,bool > mp[ N ][ N ];

int LCS(int i,int j){

    if(i == n or j == m) return dp[ i ][ j ] = 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) return dp[ i ][ j ] = 1 + LCS(i + 1,j + 1);

    return dp[ i ][ j ] = max(LCS(i,j + 1),LCS(i + 1,j));
}
void path(int i,int j,string ch){

    if(mp[ i ][ j ][ ch ]) return;

    if(i == n or j == m) { st.insert( ch ); return; }

    else if(s[ i ] == p[ j ]){ ch += s[ i ]; path(i + 1,j + 1,ch); }

    else if(dp[ i + 1 ][ j ] > dp[ i ][ j + 1 ]) path(i + 1,j,ch);

    else if(dp[ i ][ j + 1 ] > dp[ i + 1 ][ j ]) path(i,j + 1,ch);

    else { path(i + 1,j,ch); path(i,j + 1,ch); }

    mp[ i ][ j ][ ch ] = true;
}
int main(){

    op;
    file();

    int t;
    bool flag = false;

    cin >> t;

    while( t-- ){

        if( flag ) cout << endl;
        flag = true;

        cin >> s >> p;

        n = s.size();
        m = p.size();

        memset(dp,-1,sizeof dp);
        for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        mp[ i ][ j ].clear();

        st.clear();

        LCS(0,0);

        path(0,0,"");

        for(auto x : st) cout << x << endl;
    }
    return 0;
}
