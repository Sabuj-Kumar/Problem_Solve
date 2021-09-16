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
#define in freopen("int.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int N = 10005;
const int lg = log2( N );

struct node{

    int idx;
    int tup[ 2 ];

    bool operator < (const node a) const {

        return tup[ 0 ] != a.tup[ 0 ] ? tup[ 0 ] < a.tup[ 0 ] : tup[ 1 ] < a.tup[ 1 ];
    }
}arr[ N ];

string s;
int p,q,css,sz;
int LCP[ N ],rnk[ lg+5 ][ N ];

void suffix_array(){

    for(int i = 0; i < sz; i++){

        rnk[ 0 ][ i ] = s[ i ];
        arr[ i ].tup[ 0 ] = 0;
        arr[ i ].tup[ 1 ] = 0;
    }

    int pw;

    for(css = 1,pw = 1; pw <= sz; css++,pw <<= 1 ){

        for(int j = 1; j < sz; j++){

            arr[ j ].idx = j;
            arr[ j ].tup[ 0 ] = rnk[ css - 1 ][ j ];
            arr[ j ].tup[ 1 ] = j + pw < sz ? rnk[ css - 1 ][ j + pw ] : j;
        }

        sort(arr,arr+sz);
        rnk[ css ][ arr[ 0 ].idx ] = 0;

        for(int j = 1; j < sz; j++){

            rnk[ css ][ arr[ j ].idx ] = arr[ j ].tup[ 0 ] == arr[ j-1 ].tup[ 0 ] and
            arr[ j ].tup[ 1 ] == arr[ j - 1 ].tup[ 1 ] ? rnk[ css ][ arr[ j - 1 ].idx ] : j;
        }
    }

    cout << "Total substrings " << endl;
    for(int i = 0; i < sz; i++)
        cout << arr[ i ].idx << " " << s.substr(arr[ i ].idx) << endl;
    cout << endl;
}

void build_LCP_array()
{
    LCP[ 0 ] = 0;
    int i, j, id1, id2;

    for(i = 1; i < sz; i++)
    {
        id1 = arr[ i - 1 ].idx;
        id2 = arr[ i ].idx;
        LCP[ i ] = 0;

        for(j = css - 1; j >= 0; j--)
            if(rnk[ j ][ id1 ] == rnk[ j ][ id2 ])
            {
                LCP[ i ] += (1 << j);
                id1 += (1 << j);
                id2 += (1 << j);
            }
        cout << arr[ i - 1 ].idx << ' ' << arr[ i ].idx << ' ' << LCP[ i ] << endl;
    }
    for(i = 0; i < sz; i++)
        cout << i << " " << LCP[ i ] << endl;
}
int main(){

    file();

    int t;
    cin >> t;

    Case( t ){

        cin >> s;
        sz = s.size();

        cin >> p >> q;

        suffix_array();
        cout << endl;
        cout << "LCP : " << endl;
        build_LCP_array();
        cout << endl;
    }
    return 0;
}
