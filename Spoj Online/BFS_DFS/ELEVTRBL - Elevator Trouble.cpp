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

const int N = 1000001;
int f,s,g,u,d,out;
int vis[ N ];

void BFS(){

    queue< pii >q;

    q.push({s,0});

    vis[ s ] = 1;

    while(!q.empty()){

        pii p = q.front();

        q.pop();

        if(p.ft == g){

            out = p.sd;

            break;
        }
        if(p.ft + u <= f and !vis[ p.ft + u ]){

            vis[ p.ft + u ] = 1;

            q.push({p.ft + u,p.sd + 1});
        }
        if(p.ft - d >= 0 and !vis[ p.ft - d ]){

            vis[ p.ft - d ] = 1;

            q.push({p.ft - d,p.sd + 1});
        }
    }
}
int main(){

    file();

    cin >> f >> s >> g >> u >> d;
   // cout << f << " " << s << " " << g << " " << u << " " << d << endl;
    out = -1;

    BFS();

    if(out == -1) cout << "use the stairs" << endl;
    else cout << out << endl;

    return 0;
}
