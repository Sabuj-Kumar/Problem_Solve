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

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;
bool prime[ N + 10 ];
int ans = 0,len;

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

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( (p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

void seive(){

    memset(prime,true,sizeof prime);

    prime[ 0 ] = prime[ 1 ] = false;

    for(int i = 2; i < N; i++)
        if(prime[ i ])
            for(int j = i + i; j < N; j += i)
                prime[ j ] = false;
}

struct node{

    int cnt = 0;
    node *next[ 4 ];

    node(){

        for(int i = 0; i < 4; i++) next[ i ] = nullptr;
    }
} *root;

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

void Insert(string s,int len){

    node *temp = root;

    for(int i = 0; i < len; i++){

        int idx = s[ i ] - '0';

        if(temp->next[ idx ] == nullptr) temp->next[ idx ] = new node();

        temp = temp->next[ idx ];
        temp->cnt++;
    }
}

void dfs(node *temp,int level){

    ans = max(ans,level*temp->cnt);

    for(int i = 0; i < 4; i++){

        if(temp->next[ i ] != nullptr) dfs(temp->next[ i ],level + 1);
    }
}

void Delete(node *temp){

    for(int i = 0; i < 4; i++)
        if(temp->next[ i ] != nullptr) Delete( temp->next[ i ]);

    delete( temp );
}
int main(){

    file();

    int t = I();

    Case( t ){

        int n = I();
        cin.ignore();

        map<char,char> mp;
        mp[ 'A' ] = '0';
        mp[ 'C' ] = '1';
        mp[ 'G' ] = '2';
        mp[ 'T' ] = '3';

        root = new node();

        while( n-- ){

            string s;
            getline(cin,s);
            len = s.size();

            for(int i = 0; i < len; i++) s[ i ] = mp[ s[ i ] ];

            Insert(s,len);
        }

        ans = 0;

        dfs(root,0);
        cout << "Case "<< cs << " : "<< ans << endl;
        Delete( root );
    }

    return 0;
}
