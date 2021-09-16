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

    #ifndef ONLIINE_JUDGE
    in;
    #endif // ONLIINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

vector< vector< int > > c;

vector< int > Suffix_Array(const string &s){

    int classs,alv = 256,sz = s.size();
    vector< int > p( sz ),cnt(max(alv,sz),0),cc( sz );

//    c.clear();
//    c.emplace_back();
//    c[ 0 ].resize( sz );

    for(int i = 0; i < sz; i++) cnt[ s[ i ] ]++;
    for(int i = 1; i < alv; i++) cnt[ i ] += cnt[ i - 1 ];
    for(int i = 0; i < sz; i++) p[ --cnt[ s[ i ] ] ] = i;

    cc[ p[ 0 ] ] = 0;
    //c[ 0 ][ p[ 0 ] ] = 0;
    classs = 1;

    for(int i = 1; i < sz; i++){

        if(s[ p[ i ] ] != s[ p[ i - 1 ] ]) classs++;
        cc[ p[ i ] ] = classs - 1;
        //c[ 0 ][ p[ i ] ] = classs - 1;
    }

    vector< int > pn(sz),cn(sz);

    for(int lg = 0; (1 << lg) < sz; lg++){

        for(int i = 0; i < sz; i++){

            pn[ i ] = p[ i ] - (1 << lg);
            if(pn[ i ] < 0) pn[ i ] += sz;
        }

        fill(cnt.begin(),cnt.begin() + classs,0);

        //for(int i = 0; i < sz; i++) cnt[ c[ lg ][ pn[ i ] ] ]++;
        for(int i = 0; i < sz; i++) cnt[ cc[ pn[ i ] ] ]++;
        for(int i = 1; i < classs; i++) cnt[ i ] += cnt[ i - 1 ];
        for(int i = sz - 1; i >= 0; i--) p[ --cnt[ cc[ pn[ i ] ] ] ] = pn[ i ];
        //for(int i = sz - 1; i >= 0; i--) p[ --cnt[ c[ lg ][ pn[ i ] ] ] ] = pn[ i ];

        cn[ p[ 0 ] ] = 0;
        classs = 1;

        for(int i = 1; i < sz; i++){

            pii fst = {cc[ p[ i ] ],cc[(p[ i ] + (1 << lg)) % sz ]};
            pii snd = {cc[ p[ i - 1 ] ],cc[(p[ i - 1 ] + (1 << lg)) % sz ]};

            if(fst != snd) classs++;
            cn[ p[ i ] ] = classs - 1;
        }
        cc = cn;
    }
    return p;
}

vector< int > LCP(const string s,vector< int > &p){

    int sz = s.size();
    vector< int > rnk( sz );

    for(int i = 0; i < sz; i++) rnk[ p[ i ] ] = i;

    vector< int > lcp(sz - 1);

    int k = 0;

    for(int i = 0; i < sz; i++){

        if(rnk[ i ] == sz - 1) {

            k = 0;
            continue;
        }

        int j = p[ rnk[ i ] + 1 ];

        while(i + k < sz and j + k < sz and s[ i + k ] == s[ j + k ]) k++;

        lcp[ rnk[ i ] ] = k;

        if( k ) k--;
    }
    return lcp;
}
int main(){

    op;
    //file();

    int t;
    cin >> t;

    while( t-- ){

        string s;

        cin >> s;

        s += '$';

        vector< int > p = Suffix_Array( s );
        vector< int > lcp = LCP(s,p);

        s.erase(s.end()-1);
        p.erase(p.begin());

        int pos = 0;
        int sz = s.size();

        for(int i = 1; i < sz; i++) if(lcp[ pos ] < lcp[ i ]) pos = i;

        if(pos == 0) { cout << "No repetitions found!" << endl; continue; }

        int cnt = 1;

        for(int i = pos; i < sz; i++){

            if(lcp[ pos ] != lcp[ i ]) break;

            cnt++;
        }
        cout << s.substr(p[ pos ],lcp[ pos ]) << " " << cnt << endl;
    }

    return 0;
}
