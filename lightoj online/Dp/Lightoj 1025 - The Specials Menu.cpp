#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll , ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = 0; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

string s;
ll dp[ 65 ][ 65 ];

ll lcs(int i,int j){

    if(i == j) return 1;

    if(i > j) return 0;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    dp[ i ][ j ] = lcs(i + 1,j) + lcs(i,j - 1) - lcs(i + 1,j - 1);

    if(s[ i ] == s[ j ]) dp[ i ][ j ] += (1 + lcs(i + 1,j - 1) );

    return dp[ i ][ j ];
}
int main(){

    file();

    int t;

    sc( t );

    Case( t ){

        memset(dp,-1,sizeof dp);

        cin >> s;

        cout << "Case " << cs << ": "<< lcs(0,s.size() - 1) << endl;
    }
    return 0;
}
