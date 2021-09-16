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

using  namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

char s[ 2010 ],p[ 2010 ];
bool dp[ 1010 ][ 1010 ];

void solve(){

    memset(dp,false,sizeof dp);

    scanf("%s %s",s + 1,p + 1);

    int lns = strlen(s + 1);
    int lnp = strlen(p + 1);

    dp[ 0 ][ 0 ] = true;

    for(int i = 0; i <= lns; i++){

        for(int j = 0; j <= lnp; j++){

            if(dp[ i ][ j ]){

                if('a' <= s[ i + 1 ] and s[ i + 1 ] <= 'z') dp[ i + 1 ][ j ] = true;

                else if(s[ i + 1 ] == p[ j + 1 ]) dp[ i + 1 ][ j + 1 ] = true;

                if('a' <= s[ i + 1 ] and s[ i ] <= 'z' and s[ i + 1 ] - 'a' + 'A' == p[ j + 1 ])
                    dp[ i + 1 ][ j + 1 ] = true;

            }
        }
    }

    if(dp[ lns ][ lnp ]) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        solve();
    }

    return 0;
}


