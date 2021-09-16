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

const int N = 300;
string s[ N ];
bool vis[ N ][ N ];
int n,m,sg,bg;
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

bool check(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m and s[ x ][ y ] != '#';
}
void DFS(int x,int y){

    if(vis[ x ][ y ]) return;

    vis[ x ][ y ] = true;

    if(s[ x ][ y ] == 'v') bg++;
    if(s[ x ][ y ] == 'k') sg++;

    for(int i = 0; i < 4; i++){

        int xx = X[ i ] + x;
        int yy = Y[ i ] + y;

        if(check(xx,yy)) DFS(xx,yy);
    }
}
int main(){

    memset(vis,false,sizeof vis);

    file();

    cin >> n >> m;
    int sagol = 0,bagh = 0;

    for(int i = 0; i < n; i++) {

        cin >> s[ i ];

        for(int j = 0; j < m; j++){

            if(s[ i ][ j ] == 'v') bagh++;
            if(s[ i ][ j ] == 'k') sagol++;
        }
    }

//    for(int i = 0; i < n; i++) cout << s[ i ] << endl;
//    cout << endl;

    for(int i = 0; i < n; i++){

        for(int j = 0; j < m; j++){

            if(vis[ i ][ j ] == false and s[ i ][ j ] != '#'){

                sg = 0;
                bg = 0;

                DFS(i,j);

                if(sg > bg) bagh -= bg;
                else sagol -= sg;
            }
        }
    }

    cout << sagol << " " << bagh << endl;

    return 0;
}
