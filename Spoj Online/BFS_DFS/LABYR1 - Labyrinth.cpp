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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3 + 10;
int n,m,a,b,mx;
int vis[ N ][ N ];
string s[ N ];
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
void BFS(int x,int y){

    memset(vis,-1,sizeof vis);

    vis[ x ][ y ] = 0;

    queue< pii > q;

    q.push({x,y});

    mx = -1;

    while(!q.empty()){

        pii p = q.front();

        q.pop();

        if(vis[ p.ft ][ p.sd ] > mx){

            mx = vis[ p.ft ][ p.sd ];

            a = p.ft;
            b = p.sd;
        }
        for(int i = 0; i < 4; i++){

            x = p.ft + X[ i ];
            y = p.sd + Y[ i ];

            if(check(x,y) and s[ x ][ y ] == '.' and vis[ x ][ y ] == -1){

                vis[ x ][ y ] = vis[ p.ft ][ p.sd ] + 1;

                q.push({x,y});
            }
        }
    }
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        cin >> m >> n;
        //cout << n << " " << m << endl;
        for(int i = 0; i < n; i++) s[ i ].clear();
        for(int i = 0; i < n; i++) cin >> s[ i ];
//
//        for(int i = 0; i < m; i++) cout << s[ i ] << endl;
//        cout << endl;

        bool f = false;

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] == '.'){

                    BFS(i,j);

                    f = true;

                    break;
                }
            }
            if( f ) break;
        }

        BFS(a,b);

        cout << "Maximum rope length is " << mx <<"." << endl;
    }
    return 0;
}
