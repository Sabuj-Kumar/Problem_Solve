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

int n,q;
const int N = 1e5 + 100;
int table[ N ][ 30 ];
map<int,ll > out;

void sparse(vector< int > &v){

    for(int i = 0; i < n; i++) table[ i ][ 0 ] = v[ i ];

    for(int j = 1; j < 20; j++)
        for(int i = 0; (i + (1 << j) ) - 1 < n; i++)
            table[ i ][ j ] = __gcd(table[ i ][ j - 1 ],table[ i + (1 << (j - 1)) ][ j - 1 ]);
}

int get(int l,int r){

    int lg = log2(r - l + 1);

    return __gcd(table[ l ][ lg ],table[ r - (1 << lg) + 1 ][ lg ]);
}
int main(){

    file();

    cin >> n;

    vector< int > v;

    for(int i = 0; i < n; i++){

        int a;

        cin >> a;

        v.pb( a );
    }

    sparse( v );

    for(int i = 0; i < n; i++){

        int x = v[ i ];
        int last = i;

        while(last < n){

            int low = last;
            int up = n - 1;

            while(low != up){

                int mid = (low + up + 1) / 2;

                if(get(i,mid) == x) low = mid;
                else up = mid - 1;
            }

            out[ get(i,low) ] += (low - last) + 1;
            last = low + 1;
            x = get(i,last);
        }
    }

    cin >> q;

    while(q--){

        int a;

        cin >> a;

        cout << out[ a ] << endl;
    }

    return 0;
}
