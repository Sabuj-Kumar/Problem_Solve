#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define ft first
#define sd second
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdin(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

struct node{

    bool endmark;
    node *next[ 26 + 1 ];

    node(){

        endmark = false;
        for(int i = 0; i < 26; i++)next[ i ] = NULL;
    }
}*root;

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ 100010 ];

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

void siv(){

    memset(prime,true,sizeof prime);

    for(int i = 2; i < N; i++)
        if(prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = false;
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

void insert_(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int id = s[ i ] - '0';

        if(temp->next[ id ] == NULL) temp->next[ id ] = new node();

        temp = temp->next[ id ];
    }
    temp->endmark = true;
}

bool search_(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int id = s[ i ] - '0';

        if(temp->endmark) return true;

        temp = temp->next[ id ];
    }
    return false;
}
void delete_(node *temp){

    for(int i = 0; i < 26; i++)
        if(temp->next[ i ]) delete_(temp->next[ i ]);

    delete( temp );
}
int main(){

    file();

    int t = I();

    while( t-- ){

        int n = I();

        root = new node();

        vector< string > v;

        lop(i,0,n){

            string s;
            cin >> s;

            v.pb( s );

            insert_(s,s.size());
        }

        bool f = false;

        for(int i = 0; i < v.size(); i++){

            bool ans = search_(v[ i ],v[ i ].size());

            if(ans) {

                f = true;

                break;
            }
        }

        if( f ) puts("NO");
        else puts("YES");
    }

    delete( root );

    return 0;
}

