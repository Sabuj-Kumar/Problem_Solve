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
#define op ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    int testCase = I();

    while(testCase--){

        int p,n,m;

        cin >> n >> m;

        vector< vector< int > > v(n+1),ans(m+1,vector<int > (n+1,0));

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                int a;

                cin >> a;
            
                v[ i ].pb( a );
            } 

            sort(v[ i ].begin(),v[ i ].end());   
        }

        for(int i = 0; i < m; i++){

             p = 0;

            for(int j = 0; j < n; j++) if(v[ j ][ 0 ] < v[ p ][ 0 ]) p = j;

            for(int j = 0; j < n; j++){

                if(p == j){

                    ans[ i ][ j ] = v[ j ][ 0 ];
                    v[ j ].erase(v[ j ].begin());
                }
                else{

                    ans[ i ][ j ] = v[ j ].back();
                    v[ j ].pop_back();
                }
            }
        }

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++) cout << ans[ j ][ i ] << " ";

            cout << endl;
        }
    }

    return 0;
}