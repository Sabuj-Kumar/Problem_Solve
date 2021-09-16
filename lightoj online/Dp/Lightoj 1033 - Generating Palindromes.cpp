#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
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
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int dp[ 110 ][ 110 ];
string s,out;

int LCS(int i,int j){

    if(i > j) return 0;

    if(i == j) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == s[ j ]) dp[ i ][ j ] = LCS(i + 1,j - 1);

    else dp[ i ][ j ] = min(LCS(i + 1,j),LCS(i,j - 1)) + 1;

    return dp[ i ][ j ];
}

int main(){

    op
    file();

    int t;

    cin >> t;
    cin.ignore();

    Case( t ){

        memset(dp,-1,sizeof dp);

        getline(cin,s);

        int sz = s.size();

        cout << "Case " << cs << ": "<< LCS(0,sz - 1) << endl;
    }

    return 0;
}
