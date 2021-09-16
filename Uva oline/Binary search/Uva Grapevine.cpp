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

int main(){

    file();

    int n,m;

    while(scanf("%d %d",&n,&m) and n + m){

        int grid[ n + 5 ][ m + 5 ];

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        grid[ i ][ j ] = I();

        int q = I();

        while( q-- ){

            int a = I();
            int b = I();

            int pos = 0;

            for(int i = 0; i < n; i++){

                int low_ = lower_bound(&grid[ i ][ 0 ],&grid[ i ][ 0 ] + m,a) - &grid[ i ][ 0 ];

                for(int j = pos; j < n; j++){

                    if(i + j >= n or j + low_ >= m or grid[ i + j ][ j + low_ ] > b or grid[ i + j ][ j + low_ ] < a) break;

                    pos = max(pos,j + 1);
                }
            }
            printf("%d\n",pos);
        }
        puts("-");
    }

    return 0;
}
