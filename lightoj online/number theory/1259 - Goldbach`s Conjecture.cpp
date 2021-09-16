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

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e7 + 10;
vector< int > prime;
bool vis[ N ];

void seive(){

    for(int i = 2; i*i < N; i++)
        if(vis[ i ] == false)
            for(int j = i * i; j < N; j += i)
                vis[ j ] = true;

    for(int i = 2; i < N; i++) if(vis[ i ] == false) prime.pb( i );
}
int main(){

    seive();

    //file();

    int t;

    cin >> t;

    Case( t ){

        int n,cnt = 0;

        cin >> n;

        for(int i = 0; prime[ i ] <= n/2; i++)
            if(vis[ n - prime[  i ] ] == false) cnt++;

        cout << "Case " << cs << ": " << cnt << endl;
    }
    return 0;
}
