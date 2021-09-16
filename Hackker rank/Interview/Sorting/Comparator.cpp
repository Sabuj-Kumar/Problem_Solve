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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

bool cmp(pair< string,int > a,pair< string,int > b){

    if(a.sd > b.sd) return true;
    else if(a.sd == b.sd) return a.ft < b.ft;
    else return false;
}
int main(){

    //file();

    int n;

    cin >> n;

    vector< pair< string ,int > > v(n);

    for(int i = 0; i < n; i++) cin >> v[ i ].ft >> v[ i ].sd;

    sort(v.begin(),v.end(),cmp);

    for(int i = 0; i < n; i++) cout << v[ i ].ft <<" " << v[ i ].sd << endl;

    return 0;
}


