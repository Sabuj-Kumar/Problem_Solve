#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int ,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
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

struct data{

    int x,y,c;
    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

int sc() { int n; scanf("%d",&n); return n; }

vector< vector< int > > graph;
int vis[ 100010 ];

void BFS(int s,int d){

    memset(vis,-1,sizeof vis);

    queue< int > Q;
    Q.push( s );
    vis[ s ] = 0;

    while( !Q.empty() ){

        int p =  Q.front();

        Q.pop();
        if(p == d) return;

        for(auto x : graph[ p ]){

            if(vis[ x ] == -1){

                Q.push( x );
                vis[ x ] = vis[ p ] + 1;
            }
        }
    }
}
int main(){

    file();

    int test = sc();

    while( test-- ){

        int n = sc();
        vector< vector< int >> v( n+ 5);
        swap(v,graph);

        lop(i,0,n){

            int a = sc();
            int b,q = sc();

            while( q-- ){

                b = sc();
                graph[ a ].pb( b );
            }
        }

        int s = sc(),d = sc();

        BFS(s,d);

        cout << s << " " << d << " " << vis[ d ] - 1 << endl;

        if(test > 0) cout << endl;
    }

    return 0;
}
