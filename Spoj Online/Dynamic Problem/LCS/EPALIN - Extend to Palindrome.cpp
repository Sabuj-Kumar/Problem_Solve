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

const int N = 1e5 + 10;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; /// P inverse modulo M
const ll M = 1e9 + 7;
int pw[ N ],inv[ N ],HASH1[ N ],HASH2[ N ];

vector < int > Kmp_array(string p){

    int n = p.size();

    vector< int > v( n+5 );

    int i = 0,index = -1;

    v[ i ] = index;

    while(i < n){

        while(index >= 0 && p[ i ] != p[ index ]) index = v[ index ];

        i++,index++;

        v[ i ] = index;
    }

    return v;
}

int KMP(string s,string p){

    int s_size = s.size(),p_size = p.size();

    int i = 0,index = 0;

    vector< int > v = Kmp_array( p );

    while(i < s_size){

        while(index >= 0 && s[ i ] != p[ index ]) index = v[ index ];

        i++,index++;
    }

    return index;
}

int main(){

    file();

    string s;

    while(cin >> s){

        int i,sz = s.size();

        string p = s;

        reverse(p.begin(),p.end());

        int idx = KMP(s,p);

        cout << s;

        if(idx != sz) for(int i = idx; i < sz; i++) cout << p[ i ];

        cout << endl;
    }
    return 0;
}
//ok
