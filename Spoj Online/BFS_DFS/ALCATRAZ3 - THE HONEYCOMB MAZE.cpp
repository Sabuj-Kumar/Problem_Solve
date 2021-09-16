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

string s[ 110 ];
bool vis[ 110 ][ 110 ],flag;
int n,m,a,b;
int X[ ] = {0,1,0,-1};
int Y[ ] = {1,0,-1,0};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
bool DFS(int x,int y,int dis){

    s[ x ][ y ] = '*';

    for(int i = 0; i < 4; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(check(xx,yy)){

            if(xx == a and yy == b) { if(dis - 1 <= 0) return true; }

            else if(s[ xx ][ yy ] == '.') { if( DFS(xx,yy,dis - 1) ) return true; }
        }
    }

    s[ x ][ y ] = '.';

    return false;
}
int main(){

    file();

    int dis,x,y;

    cin >> n >> m >> dis >> a >> b;
    cin.ignore();
    a--;
    b--;

    string ss = "",ch[ 110 ];

    for(int i = 0; i < n; i++) getline(cin,ch[ i ]);

    for(int i = 0; i < n; i++){

        ss = "";

        for(int j = 0; j < ch[ i ].size(); j++) if(ch[ i ][ j ] != ' ') ss += ch[ i ][ j ];

        s[ i ] = ss;
    }

    flag = DFS(a,b,dis);

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
