#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
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

struct node{

    db pv;
    int x;
};

db p;
int n;
vector< node > v;
int dp[ 110 ];

int DP(int idx,db d){

    if(d > p) return 0;

    if(idx == n) return 0;

    if(dp[ i ] != -1) return dp[ i ];

    db a = 0.0;

    for(int i = idx; i < n; i++){


    }
}
int main(){

    op;
    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> p >> n;

        v.clear();
        v.resize(n);

        for(int i = 0; i < n; i++){

            int a;
            db b;

            cin >>a >> b;

            v[ i ].pv = b;
            v[ i ].x  = a;
        }


    }
    return 0;
}
