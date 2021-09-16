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

struct Node{

    int a,b,c;

    bool operator < (const Node &x) const{

        return x.c < c;
    }
};

priority_queue< Node > q;
const int N = 4000;
ll ans;
int a[ N ];
int parent[ N ];
void init_(int n) { for(int i = 1; i <= n; i++) parent[ i ] = i; }
int search_parent(int p){ return parent[ p ] == p ?  p : parent[ p ] = search_parent( parent[ p ] ); }
void union_(int x,int y){ parent[ x ] = y; }

void mini(int edge){

    while( !q.empty() && edge){

        Node n = q.top();

        q.pop();

        int x = search_parent(n.a);
        int y = search_parent(n.b);

        if(x != y){

            ans += n.c;

            edge--;

            union_(x,y);
        }
    }
}
int main(){

    //file();

    ll n,m;

    cin >> n >> m;

    init_( n );

    for(int i = 0; i < m; i++){

        ll a,b,c;

        cin >> a >> b >> c;

        q.push({a,b,c});
    }

    ans = 0;

    mini( m );

    cout << ans << endl;

    return 0;
}

