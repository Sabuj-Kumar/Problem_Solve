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
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

const int MX = 4 * 1e5 + 10;

vector< ll > P,Lcp;
pll tree[ MX ];

vector< ll > Suffix_Array(const string &s){

    ll sz = s.size(),alv = 256;
    vector< ll > p(sz),c(sz),cnt(max(alv,sz),0);

    for(int i = 0; i < sz; i++) cnt[ s[ i ] ]++;
    for(int i = 1; i < alv; i++) cnt[ i ] += cnt[ i - 1 ];
    for(int i = 0; i < sz; i++) p[ --cnt[ s[ i ] ] ] = i;

    c[ p[ 0 ] ] = 0;
    ll css = 1;

    for(int i = 1; i < sz; i++){

        if(s[ p[ i ] ] != s[ p[ i - 1 ] ]) css++;

        c[ p[ i ] ] = css - 1;
    }

    vector< ll > pn(sz,0),cn(sz,0);

    for(int lg = 0; (1 << lg) < sz; lg++){

        for(int i = 0;  i < sz; i++){

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

            pii fst = {c[ p[ i ] ],c[ (p[ i ] + (1 << lg)) % sz ]};
            pii snd = {c[ p[ i - 1 ] ],c[ (p[ i - 1 ] + (1 << lg)) % sz ]};

            if(fst != snd) css++;

            cn[ p[ i ] ] = css - 1;
        }

        c = cn;
    }

    return p;
}

vector< ll > LCP(const string &s,const vector< ll > &p){

    ll sz = s.size(),k = 0;
    vector< ll > lcp(sz-1,0),rnk(sz,0);

    for(int i = 0; i < sz; i++) rnk[ p[ i ] ] = i;

    for(int i = 0; i < sz; i++){

        if(rnk[ i ] == sz - 1) { k = 0; continue; }

        int j = p[ rnk[ i ] + 1 ];

        while(i + k < sz and j + k < sz and s[ i + k ] == s[ j + k ]) k++;

        lcp[ rnk[ i ] ] = k;

        if( k ) k--;
    }

    return lcp;
}

pll check(pll a,pll b){

    a.ft = min(a.ft,b.ft);
    a.sd = max(a.sd,b.sd);

    return a;
}
void build_tree(int node,int l,int r){

    if(l == r){

        tree[ node ] = {Lcp[ l ],P[ l ]};

        return;
    }

    int mid = (l + r) / 2;

    build_tree(node * 2,l,mid);
    build_tree(node * 2 + 1,mid + 1,r);

    tree[ node ] = check(tree[ node * 2 ],tree[ node * 2 + 1 ]);
}

pll query(int node,int L,int R,int l,int r){

    if(l > r) return {INT_MAX,-1};

    if(l == L and r == R) return tree[ node ];

    int mid = (L + R) / 2;

    pll p = query(node * 2,L,mid,l,min(mid,r));
    pll q = query(node * 2 + 1,mid + 1,R,max(l,mid + 1),r);

    return check(p,q);
}
int main(){

    op;
    file();

    int n;

    while(cin >> n and n){

        string s;

        cin >> s;

        int sz = s.size();

        s += '$';

        vector< ll > p = Suffix_Array( s );
        vector< ll > lcp = LCP(s,p);

        p.erase(p.begin());
        s.erase(s.end()-1);

        P = p;
        Lcp = lcp;

        build_tree(1,0,sz-1);

        ll ln = 0,idx = -1;

        for(int i = 0; i + n - 2 < sz; i++){

            if(i + n - 2 < 0) continue;

            pll x = query(1,0,sz-1,i,(i + n - 2));

            if(x.ft > 0){

                x.sd = max(x.sd,P[ i - 1 ]);

                if(x.ft == ln) idx = max(idx,x.sd);
                else if(x.ft > ln){ ln = x.ft; idx = x.sd; }
            }
        }

        if(idx == -1) cout << "none" << endl;
        else {

            if(ln == INT_MAX) ln = idx+1,idx = 0;

            cout << ln << " " << idx << endl;
        }
    }

    return 0;
}
