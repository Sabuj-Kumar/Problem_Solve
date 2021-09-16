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
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int sz,sz1,sz2;

vector< int > Suffix_Array(const string &s){

    int sz = s.size(),alv = 256;

    vector< int > p( sz ),cnt(max(sz,256),0),c( sz );

    for(int i = 0; i < sz; i++) cnt[ s[ i ] ]++;
    for(int i = 1; i < 256; i++) cnt[ i ] += cnt[ i - 1 ];
    for(int i = 0; i < sz; i++) p[ --cnt[ s[ i ] ] ] = i;

    c[ p[ 0 ] ] = 0;
    int css = 1;

    for(int i = 1; i < sz; i++){

        if(s[ p[ i ] ] != s[ p[ i - 1] ]) css++;

        c[ p[ i ] ] = css - 1;
    }

    vector<int > pn( sz ),cn( sz );

    for(int lg = 0; (1 << lg) < sz; lg++){

        for(int i = 0; i < sz; i++){

            pn[ i ] = p[ i ] - (1 << lg);

            if(pn[ i ] < 0) pn[ i ] += sz;
        }

        fill(cnt.begin(),cnt.begin()+css,0);

        for(int i = 0; i < sz; i++) cnt[ c[ pn[ i ] ] ]++;
        for(int i = 1; i < css; i++) cnt[ i ] += cnt[ i - 1 ];
        for(int i = sz - 1; i >= 0; i--) p[ --cnt[ c[ pn[ i ] ] ] ] = pn[ i ];

        cn[ p[ 0 ] ] = 0;
        css = 1;

        for(int i = 1; i < sz; i++){

            pii fst = {c[ p[ i ] ],c[ (p[ i ] + (1 << lg)) % sz] };
            pii snd = {c[ p[ i -1 ] ],c[ (p[ i - 1 ] + (1 << lg)) % sz ] };

            if(fst != snd) css++;

            cn[ p[ i ] ] = css - 1;
        }

        c = cn;
    }
    return p;
}

vector< int > LCP(const string &s,const vector< int > &p){

    int sz = s.size();

    vector< int > rnk(sz,0),lcp(sz-1,0);

    for(int i = 0; i < sz; i++) rnk[ p[ i ] ] = i;

    int k = 0;

    for(int i = 0; i < sz; i++){

        if(rnk[ i ] == sz - 1){ k = 0; continue; }

        int j = p[ rnk[ i ] + 1 ];

        while(i + k < sz and j + k < sz and s[ i + k ] == s[ j + k ]) k++;

        lcp[ rnk[ i ] ] = k;

        if( k ) k--;
    }
    return lcp;
}

int check(int val){

    return (val < (sz - sz1 - sz2 - 2)) ? 1 : (val < (sz - sz2 - 1)) ? 2 : 3;
}
int main(){

    file();

    int t = I();

    Case( t ){

        string ch,s,ss,sss;

        cin >> s >> ss >> sss;

        sz1 = ss.size();
        sz2 = sss.size();

        s += '$';
        ss += '#';
        sss += '!';

        ch = s + ss + sss;

        sz = ch.size();
        vector< int > p = Suffix_Array( ch );
        vector< int > lcp = LCP(ch,p);

//        for(int i = 0; i < sz; i++) cout << i << " "<< p[ i ] << " " << ch.substr(p[ i ]) << endl;
//        cout << endl;
//        for(int i = 0; i < sz-1; i++) cout << i << " " << i + 1 << " "<< lcp[ i ] << endl;
//        cout << endl;

        int mx = INT_MIN;

        for(int i = 2; i < sz; i++){

            int a = check(p[ i ]);
            int b = check(p[ i - 1 ]);
            int c = check(p[ i - 2 ]);

            //cout << i - 2 << " " <<p[ i - 2 ] << " " << i - 1 << " " << p[ i - 1 ] << " "<<  i <<" " << p[ i ] << endl;

            if(a != b and b != c and a != c){

//                cout <<"range Saffix "<< p[ i - 2 ] << " " << p[ i - 1 ] << " " << p[ i ] << endl;
//                cout << "range find "<< lcp[ i ] << " " << lcp[ i - 1 ] << endl;
                mx = max(mx,min(lcp[ i-2 ],lcp[ i - 1 ]));

            }

        }

        cout << "Case " << cs << ": " << mx << endl;
    }
    return 0;
}
