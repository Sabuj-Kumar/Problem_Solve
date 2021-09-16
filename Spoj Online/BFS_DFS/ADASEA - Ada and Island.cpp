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
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e3+10;
ll n,m,cnt;
bool vis[ N ][ N ];
string s[ N ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};

bool good(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}
void DFS(int x,int y){

    vis[ x ][ y ] = true;

    cnt++;

    for(int i = 0; i < 4; i++){

        int xx = x + X[ i ];
        int yy = y + Y[ i ];

        if(good(xx,yy) and !vis[ xx ][ yy ] and s[ xx ][ yy ] == '#'){

            DFS(xx,yy);
        }
    }
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        cin >> n >> m;

        memset(vis,false,sizeof vis);

        for(int i = 0; i < n; i++) cin >> s[ i ];

        ll div = n * m,ans = 0;

        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){

            if(!vis[ i ][ j ] and s[ i ][ j ] == '#'){

                cnt = 0;

                DFS(i,j);

                ans += (1LL * cnt * cnt);
            }
        }

        ll gcd = __gcd(ans,div);

        ans /= gcd;
        div /= gcd;

        if(div == 1) cout << ans << endl;
        else cout << ans << " / " << div << endl;
    }
    return 0;
}
