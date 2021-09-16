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

const int N = 110;
int n,m;
int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
ll dis[ N ][ N ][ 16 ];
bool vis[ N ][ N ][ 16 ];
string s[ N ];
ll ans = 0;
queue< pair< pii,int > > q;

bool valid(int x,int y){

    return x >= 0 and x < n and y >= 0 and y < m;
}

bool check(char c,int mask){

    return ((c == 'B' and (mask & 1)) or (c == 'Y' and (mask & 2)) or (c == 'R' and (mask & 4))
            or (c == 'G' and (mask & 8)) or (c == '.') or (c == '*') or (c == 'b') or (c == 'y')
            or (c == 'r') or (c == 'g') or (c == 'X'));
}
void BFS(){

    while(!q.empty()){

        pii p =q.front().ft;
        int mask,new_mask;
        mask = new_mask = q.front().sd;

        q.pop();

        if(s[ p.ft ][ p.sd ] == 'X'){

            ans = dis[ p.ft ][ p.sd ][ mask ];

            return;
        }

        if(s[ p.ft ][ p.sd ] == 'b') new_mask |= 1;
        else if(s[ p.ft ][ p.sd ] == 'y') new_mask |= 2;
        else if(s[ p.ft ][ p.sd ] == 'r') new_mask |= 4;
        else if(s[ p.ft ][ p.sd ] == 'g') new_mask |= 8;

        for(int i = 0; i < 4; i++){

            int x = p.ft + X[ i ];
            int y = p.sd + Y[ i ];

            if(valid(x,y) and !vis[ x ][ y ][ new_mask ]){

                if(check(s[ x ][ y ],new_mask)){

                    dis[ x ][ y ][ new_mask ] = dis[ p.ft ][ p.sd ][ mask ] + 1;
                    vis[ x ][ y ][ new_mask ] = true;
                    q.push({{x,y},new_mask});
                }
            }
        }
    }
}
int main(){

    file();

    while(cin >> n >> m and (n + m)){

        while(!q.empty()) q.pop();
        memset(dis,0,sizeof dis);
        memset(vis,false,sizeof vis);

        for(int i = 0; i < n; i++) {

            cin >> s[ i ];

            for(int j = 0; j < m; j++) if(s[ i ][ j ] == '*') { q.push({{i,j},0}); }
        }

        ans = -1;

        BFS();

        if(ans == -1) puts("The poor student is trapped!");
        else printf("Escape possible in %lld steps.\n",ans);
    }
    return 0;
}
