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

int n;
int root,des,a;
vector< int > graph[ 50100 ];
int path[ 50100 ];

void print(int parent){

    if(parent == -1) return;

    print(path[ parent ]);

    printf("%d ",parent);
}
void BFS(int root){

    queue< int > q;

    path[ root ] = -1;

    q.push( root );

    while( !q.empty() ){

        int v = q.front();
        q.pop();

        for(auto x : graph[ v ]){

            if(path[ x ] == 0){

                path[ x ] = v;

                if(x == des) {

                    print(v);
                    return;
                }
                q.push( x );
            }
        }
    }
}
int main(){

    file();

    int t = I();

    Case( t ){

        memset(path,0,sizeof path);

        for(int i = 0; i < 50100; i++) graph[ i ].clear();

        n = I();

        for(int i = 0; i < n; i++){

            if(i == 0) { a = I(); root = a; }
            else{

                des = I();
                graph[ a ].pb( des );
                graph[ des ].pb( a );
                a = des;
            }
        }

        for(int i = 0; i < 50005; i++)
            if(graph[ i ].size() > 1) sort(graph[ i ].begin(),graph[ i ].end());

        printf("Case %d:\n",cs);
        BFS( root );

        printf("%d\n",des);
    }
    return 0;
}
