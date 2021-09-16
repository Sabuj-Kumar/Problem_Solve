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

vector< vector< int > > c;
const int alv = 256;

vector< int > suffix_array(const string &s){

    int classs,sz = s.size();

    vector< int > p( sz ),cnt( max(sz,alv),0 );
    c.clear();
    c.emplace_back();
    c[ 0 ].resize( sz );

    for(int i = 0; i < sz; i++) cnt[ s[ i ] ]++;
    for(int i = 1; i < alv; i++) cnt[ i ] += cnt[ i - 1 ];
    for(int i = 0; i < sz; i++) p[ --cnt[ s[ i ] ] ] = i;

    c[ 0 ][ p[ 0 ] ] = 0;
    classs = 1;

    for(int i = 1; i < sz; i++){

        if(s[ p[ i ] ] != s[ p[ i - 1 ] ]) classs++;
        c[ 0 ][ p[ i ] ] = classs - 1;
    }

    vector< int > pn( sz ),cn( sz );

    for(int h = 0; (1 << h) < sz; h++){

        for(int i = 0; i < sz; i++){

            pn[ i ] = p[ i ] - (1 << h);
            if(pn[ i ] < 0) pn[ i ] += sz;
        }

        fill(cnt.begin(),cnt.begin() + classs,0);

        for(int i = 0; i < sz; i++) cnt[ c[ h ][ pn[ i ] ] ]++;
        for(int i = 1; i < classs; i++) cnt[ i ] += cnt[ i - 1 ];
        for(int i = sz - 1; i >= 0; i--) p[ --cnt[ c[ h ][ pn[ i ] ] ] ] = pn[ i ];

        cn[ p[ 0 ] ] = 0;
        classs = 1;

        for(int i = 1; i < sz; i++){

            pii fst = {c[ h ][ p[ i ] ],c[ h ][ (p[ i ] + (1 << h)) % sz ]};
            pii scd = {c[ h ][ p[ i - 1 ] ],c[ h ][ (p[ i - 1 ] + (1 << h)) % sz ]};

            if(fst != scd) classs++;

            cn[ p[ i ] ] = classs - 1;
        }
        c.pb(cn);
    }
    return p;
}
int main(){

    op;
    //file();

    string s;

    cin >> s;
    s += '$';
    vector< int > ans = suffix_array( s );
    ans.erase(ans.begin());
    for(int  i = 0; i < ans.size(); i++) cout << ans[ i ] << endl;

    return 0;
}
