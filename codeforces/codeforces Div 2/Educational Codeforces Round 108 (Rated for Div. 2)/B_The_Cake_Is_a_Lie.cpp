#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long 
#define ull unsinged long long 
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n);
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif //ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int grid[ 110 ][110 ];
int n,m,k;
bool flag;

void DP(int x,int y,int k){

    if(x > n or y > m or k < 0) return;

    if(x == n and y == m){

        if(k == 0) {

            flag = true;
        }

        return;
    }

    if(grid[ x ][ y ] != -1) return ;

    grid[ x ][ y ] = k;

    DP(x,y + 1,k - x);
    DP(x + 1,y,k - y);
}
int main(){

    int t;

    cin >> t;

    while(t--){

        flag = false;
        memset(grid, -1,sizeof grid);

        cin >> n >> m >> k;

        DP(1,1,k);

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}