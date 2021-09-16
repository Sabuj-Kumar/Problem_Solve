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

int main(){

    //file();

    int n;
    bool f = false;

    while(cin >> n){

        if( f ) cout << endl;
        f = true;

        int m = 2 * n;
        int a[ 2 * n + 5];

        a[ 0 ] = a[ 1 ] = 1;

        for(int i = 2; i <= n; i++){

            a[ i ] = 0;

            for(int j = 0; j < i; j++){

                a[ i ] += a[ j ] * a[ i - j - 1 ];
            }
        }

        cout << a[ n ] << endl;
    }
    return 0;
}
