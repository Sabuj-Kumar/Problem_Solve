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
#define sl( n ) scanf("%lld",&n);
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

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int GX[ ] = {2,2,1,1,-2,-2,-1,-1};
int GY[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 101;
string s[ N ];
int m,n,Bx,By;

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
int BFS(int x,int y){

    queue< pii > Q;

    Q.push({x,y});

    vector< vector< int > > vis(n,vector< int > (m,-1));

    vis[ x ][ y ] = 0;

    while(!Q.empty()){

        pii u = Q.front();

        Q.pop();

        for(int i = 0; i < 8; i++){

            int p = u.ft + X[ i ];
            int q = u.sd + Y[ i ];

            if(check(p,q) and s[ p ][ q ] != '#' and vis[ p ][ q ] == -1){

                vis[ p ][ q ] = vis[ u.ft ][ u.sd ] + 1;

                Q.push({p,q});
            }
        }
    }

//    for(int i = 0; i < n; i++){
//
//        for(int j = 0; j < m; j++)
//            cout << vis[ i ][ j ];
//        cout << endl;
//    }
//    cout << endl;

    return vis[ Bx ][ By ];
}
int main()
{
    file();

    int test;

    cin >> test;

    while(test--){

        cin >> n >> m;

        int x,y;

        cin.ignore();

        for(int i = 0; i < n; i++) getline(cin,s[ i ]);

        for(int i = 0; i < n; i++){

            for(int j = 0; j < m; j++){

                if(s[ i ][ j ] == 'A'){

                    x = i,y = j;
                }
                else if(s[ i ][ j ] == 'B'){

                    Bx = i,By = j;
                }
                else if(s[ i ][ j ] == 'Z'){

                    s[ i ][ j ] = '#';

                    for(int k = 0; k < 8; k++){

                        int p = i + GX[ k ] ;
                        int q = j + GY[ k ];

                        if(check(p,q) and s[ p ][ q ] == '.') s[ p ][ q ] = '#';
                    }
                }

            }
        }

//        for(int i = 0; i < n; i++){
//
//            cout << s[ i ] << endl;
//        }
//
//        cout << endl;

        int ans = BFS(x,y);

        if(ans == -1) cout << "King Peter, you can't go now!" << endl;
        else cout << "Minimal possible length of a trip is " << ans << endl;

        for(int i = 0; i < n; i++) s[ i ].clear();
    }
    return 0;
}

