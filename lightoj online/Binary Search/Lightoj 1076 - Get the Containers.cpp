#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ldb long double
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

int n;
int ar[ 1010 ];

bool check(int val,int m){

    int sum = 0,cnt = 1;

    for(int i = 0; i < n; i++){

        if(val < ar[ i ]) return false;

        if(sum + ar[ i ] <= val) sum += ar[ i ];
        else sum = ar[ i ],cnt++;

        if( cnt > m ) return false;
    }
    return true;
}
ll Binary_Search( int m ){

    ll l = 0,r = 1e9,mid = 0;

    while(l < r){

        mid = (l + r) / 2;

        if(check( mid,m )) r = mid;

        else l = mid + 1;
    }

    return r;
}
int main(){

    //file();

    int t = I();

    Case( t ){

        n = I();
        int m = I();

        for(int i = 0; i < n; i++) ar[ i ] = I();

        ll ans = Binary_Search( m );

        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}
