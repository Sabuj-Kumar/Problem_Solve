#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

typedef map<ll,multiset<pll>> list_;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }
struct data{

    ll node;
    ll cs;

    data(){}
    data(int _node,int _cs) { node = _node,cs = _cs; }

    bool operator < (const data &x) const {

        return this->cs > x.cs;
    }
};

const int N = 3100;

ll cost[ N ];

void Dijstra(list_ &graph,set< ll > &v,ll root){

    for(auto x : v) cost[ x ] = INT_MAX;

    priority_queue< pll,vector< pll >,greater< pll > > q;

    q.push({0,root});

    cost[ root ] = 0;

    while(!q.empty()){

        auto p = q.top();

        q.pop();

        for(auto x : graph[ p.sd ]){

            if(cost[ x.sd ] > cost[ p.sd ] + x.ft ){

                cost[ x.sd ] = cost[ p.sd ] + x.ft;

                q.push({cost[ x.sd ],x.sd});
            }
        }
    }
}
int main(){

    //file();

    int t = I();

    while(t--){

        list_ graph;
        set< ll > st;

        int n,m,s;
        n = Il(),m = Il();

        while(m--){

            ll a = Il(),b = Il(),c = Il();

            st.insert(a);
            st.insert(b);

            if(!graph.count(a)) { multiset< pll > ml; graph[ a ] = ml; }

            if(!graph.count(b)) { multiset< pll > ml; graph[ b ] = ml; }

            graph[ a ].insert({c,b});
            graph[ b ].insert({c,a});
        }

        s = Il();

        Dijstra( graph,st,s );

        for(int i = 1; i <= n; i++){

            if(i != s and (cost[ i ] != INT_MAX and cost[ i ] != 0)) printf("%lld",cost[ i ]);
            else if(i != s) printf("-1");

            if(i != s and i < n) printf(" ");
        }
        puts("");
    }
    return 0;
}
