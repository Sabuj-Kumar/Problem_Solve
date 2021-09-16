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
    in
    #endif // ONLINE_JUDGE
}

int sz,sp;
int dp[ 2010 ][ 2010 ];
string s,p;

int distance(int i,int j){

    if(i == sz) return sp - j;
    if(j == sp) return sz - i;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) return dp[ i ][ j ] = distance(i + 1,j + 1);

    int a = 1 + distance(i + 1,j + 1);
    int b = 1 + distance(i,j + 1);
    int c = 1 + distance(i + 1,j);

    return dp[ i ][ j ] = min(a,min(b,c));
}

int main(){

    file();

    int t;

    sc( t );

    while( t-- ){

        memset(dp,-1,sizeof dp);

        cin >> s;
        cin >> p;

        sz = s.size();
        sp = p.size();

        int need = distance(0,0);

        printf("%d\n",need);
    }
    return 0;
}
