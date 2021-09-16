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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 5010;

string s,p;
int sz,dp[ N ][ N ];

int LCS(int i,int j){

    if(i == sz) return 0;
    if(j == sz) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) return dp[ i ][ j ] = 1 + LCS(i + 1,j + 1);
    else return dp[ i ][ j ] = max(LCS(i + 1,j),LCS(i,j + 1));
}
int main(){

   // file();

    cin >> s >> p;

    sz = s.size();

    memset(dp,-1,sizeof dp);

    cout << LCS(0,0) << endl;


    return 0;
}
