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

const int N = 1e3+5;
int ar[ N ][ N ];
int n,m,x1,x2,y1,y2;

bool check(int i,int j){

    int v = ar[ i ][ j ];

    return ar[ i - 1 ][ j ] == v and ar[ i + 1 ][ j ] == v and ar[ i ][ j - 1 ] == v and ar[ i ][ j + 1 ] == v;
}

void DFS(int i,int j){

    int v = ar[ i ][ j ];

    int p = i,q = j;

    while(ar[ p ][ q ] == v and q < m) q++;

    q--;
    x2 = q;
    q = j;

    while(ar[ p ][ q ] == v and q >= 0) q--;

    q++;
    x1 = q;
    q = j;

    while(ar[ p ][ q ] == v and p < n) p++;

    p--;
    y2 = p;
    p = i;

    while(ar[ p ][ q ] == v and p >= 0) p--;

    p++;
    y1 = p;
    p = i;
}
int main(){

    file();

    int t;

    sc( t );

    Case( t ){

        sc( n );
        sc( m );

        int ans = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        sc(ar[ i ][ j ]);

//        for(int i = 0; i < n; i++){
//
//            for(int j = 0; j < m; j++) cout << ar[ i ][ j ] << " ";
//            cout << endl;
//        }
//        cout << endl;

        for(int i = 1; i < n - 1; i++){

            for(int j = 1; j < m - 1; j++){

                if(check(i,j)){

                    DFS(i,j);

                    ans = max(ans,(x2 - x1) + (y2 - y1) + 1);
                }
            }
        }

        cout << "Case " << cs << ": " << ans << endl;
    }

    return 0;
}
