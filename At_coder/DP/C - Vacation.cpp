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
#define op ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e5+10;
ll n,a[ N ][ 3 ];
ll dp[ N ][ 3 ];

ll Call(int idx,int pre) {

    if(idx == n) return 0;

    if(dp[ idx ][ pre ] != -1) return dp[ idx ][ pre ];

    ll ans = 0;

    if(pre == 0){

        ans = max(ans,a[ idx ][ 1 ] + Call(idx + 1,1));
        ans = max(ans,a[ idx ][ 2 ] + Call(idx + 1,2));
    }
    else if(pre == 1){

        ans = max(ans,a[ idx ][ 0 ] + Call(idx + 1,0));
        ans = max(ans,a[ idx ][ 2 ] + Call(idx + 1,2));
    }
    else if(pre == 2){

        ans = max(ans,a[ idx ][ 1 ] + Call(idx + 1,1));
        ans = max(ans,a[ idx ][ 0 ] + Call(idx + 1,0));
    }
    else{

        ans = max(ans,a[ idx ][ 0 ] + Call(idx + 1,0));
        ans = max(ans,a[ idx ][ 1 ] + Call(idx + 1,1));
        ans = max(ans,a[ idx ][ 2 ] + Call(idx + 1,2));
    }
    return dp[ idx ][ pre ] = ans;
}
int main(){

    memset(dp,-1,sizeof dp);

    file();

    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[ i ][ 0 ] >> a[ i ][ 1 ] >> a[ i ][ 2 ];

    cout << Call(0,3) << endl;

    return 0;
}
