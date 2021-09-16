#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%d",&n)
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

const int N = 1e6 + 10;
bool p[ N + 10 ];

void sieve(){

    int rot = sqrt( N );

    for(int i = 2; i <= rot; i++)
        if(p[ i ]== false)
            for(int j = i + i; j < N; j += i)
                p[ j ] = true;
}
int main(){

    sieve();

    int n,i;

    cin >> n;

    for(i = 1; i < 1001; i++)
        if(p[ n * i + 1 ] == true) break;

    cout << i << endl;

    return 0;
}

