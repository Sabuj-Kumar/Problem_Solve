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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

vector< int > fill_array(int n){

    vector< int > v(n+1,0);

    priority_queue< pair< int,pii > > q;

    q.push({n,{-1,-n}});
    int cnt = 0;

    while(!q.empty()){

        int l = -q.top().sd.ft;
        int r = -q.top().sd.sd;

        q.pop();

        int mid = (l + r) / 2;
        v[ mid ] = ++cnt;

        if(l == r) continue;

        if(l < mid) q.push({mid - l,{-l,-(mid - 1)}});
        if(r > mid) q.push({r - mid,{-(mid + 1),-r}});
    }

    return v;
}
int main(){

    file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        vector< int > v = fill_array(n);

        for(int i = 1; i <= n; i++) cout << v[ i ] << " ";

        cout << endl;
    }
    return 0;
}
