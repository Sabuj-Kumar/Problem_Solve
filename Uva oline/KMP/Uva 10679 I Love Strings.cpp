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

string s,p;

vector< int > temp_array(const string &p){

    int sz = p.size();
    vector< int > ar(sz);
    int i = 0,idx = -1;

    ar[ i ] = idx;

    while(i < sz){

        if(idx >= 0 and p[ i ] != p[ idx ]) idx = ar[ idx ];

        i++,idx++;

        ar[ i ] = idx;
    }
    return ar;
}

bool KMP(const string &s,const string &p){

    int sz = s.size(),pz = p.size();
    vector< int > temp = temp_array( p );
    int i = 0,idx = 0;

    while(i < sz){

        if(idx >= 0 and s[ i ] != p[ idx ]) idx = temp[ idx ];

        i++,idx++;

        if(idx == pz) return true;
    }
    return false;
}

int main(){

    op;
    file();

    int t;

    cin >> t;

    Case( t ){

        cin >> s;

        int q;

        cin >> q;

        while( q-- ){

            cin >> p;

            bool ans = KMP(s,p);

            if( ans ) cout << "y" << endl;
            else cout << "n" << endl;
        }
    }
    return 0;
}

