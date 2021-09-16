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
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 1e7+100;
int prime[ N ];
vector< int > v;

void seive(){

    prime[ 0 ] = 0;
    prime[ 1 ] = 0;

    for(int i = 2; i < N; i++){

        if(prime[ i ] == 0){

            prime[ i ]++;

            for(int j = i + i; j < N; j += i) prime[ j ]++;
        }
    }

    for(int i = 2; i < N; i++)  if(prime[ i ] >= 3) v.pb( i );
}
int main(){

    seive();

    file();

    int t;

    cin >> t;

    while(t--){

        int n;

        cin >> n;

        cout << v[ n - 1 ] << endl;
    }

    return 0;
}

