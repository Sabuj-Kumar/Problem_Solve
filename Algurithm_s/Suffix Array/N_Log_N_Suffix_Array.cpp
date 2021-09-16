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

vector< vector< int > > c;

vector< int > sort_cyclic_shifts(string const &s){

    int n = s.size();
    const int alphabet = 256;

    c.clear();
    c.emplace_back();
    c[ 0 ].resize( n );

    vector< int > p( n ),cnt(max(alphabet,n),0);

    for(int i = 0; i < n; i++) cnt[ s[ i ] ]++;
    for(int i = 1; i < alphabet; i++) cnt[ i ] += cnt[ i-1 ];
    for(int i = 0; i < n; i++) p[ --cnt[ s[ i ] ] ] = i;

    c[ 0 ][ p[ 0 ] ] = 0;

    int classes = 1;

    for (int i = 1; i < n; i++) {

        if(s[ p[ i ] ] != s[ p[ i - 1 ] ]) classes++;

        c[ 0 ][ p[ i ] ] = classes - 1;
    }

    vector< int > pn( n ),cn( n );

    for (int h = 0; (1 << h) < n; ++h) {

        for (int i = 0; i < n; i++) {

            pn[ i ] = p[ i ] - (1 << h);

            if (pn[ i ] < 0) pn[ i ] += n;
        }

        fill(cnt.begin(),cnt.begin() + classes,0);

        for (int i = 0; i < n; i++) cnt[ c[ h ][ pn[ i ] ] ]++;
        for (int i = 1; i < classes; i++) cnt[ i ] += cnt[ i - 1 ];
        for (int i = n-1; i >= 0; i--) p[ --cnt[ c[ h ][ pn[ i ] ] ] ] = pn[ i ];

        cn[ p[ 0 ] ] = 0;
        classes = 1;

        for (int i = 1; i < n; i++) {

            pii cur = { c[ h ][ p[ i ] ],c[ h ][ (p[ i ] + (1 << h)) % n ] };
            pii prev = { c[ h ][ p[ i - 1 ] ],c[ h ][ ( p[ i - 1 ] + (1 << h)) % n ] };

            if (cur != prev) ++classes;
            cn[ p[ i ] ] = classes - 1;
        }
        c.push_back( cn );
    }
    return p;
}

int compare(int i, int j, int l, int k) {

    pii a = { c[ k ][ i ],c[ k ][ (i + l - (1 << k)) % n ]};
    pii b = { c[ k ][ j ],c[ k ][ (j + l - (1 << k)) % n ]};

    return a == b ? 0 : a < b ? -1 : 1;
}

vector<int> suffix_array_construction(string s) {

    s += "$";

    vector< int > sorted_shifts = sort_cyclic_shifts( s );

    sorted_shifts.erase(sorted_shifts.begin());

    return sorted_shifts;
}
int lcp(int i, int j){

    int log_n = c.size() - 1;
    int ans = 0;

    for (int k = log_n; k >= 0; k--) {

        if (c[ k ][ i ] == c[ k ][ j ]) {

            ans += 1 << k;
            i += 1 << k;
            j += 1 << k;
        }
    }
    return ans;
}
vector<int> lcp_construction(string const &s, vector<int> const& p) {

    int n = s.size();

    vector< int > rnk(n,0);

    for (int i = 0; i < n; i++) rnk[ p[ i ] ] = i;

    int k = 0;

    vector< int > lcp(n-1, 0);

    for (int i = 0; i < n; i++) {

        if (rnk[ i ] == n - 1) { k = 0; continue; }

        int j = p[ rnk[ i ] + 1 ];

        while (i + k < n && j + k < n && s[ i + k ] == s[ j + k ]) k++;

        lcp[ rnk[ i ] ] = k;

        if( k )k--;
    }
    return lcp;
}

int main(){

    file();


    return 0;
}

