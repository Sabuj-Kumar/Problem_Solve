#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair< ll,ll >
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define pi acos(-1)
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}
struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_){ x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }

//    bool operator < ( const data &a ) const {
//
//        return cost > a.cost;
//    }
};

ll gcd(ll a,ll b){

    if(b == 0) return a;
    return gcd(b,a%b);
}

const int mx = 1e6;
const int mx_= 1e9;
const ll mx__=1e18;
const int N = 1e6 + 7;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; // P inverse modulo M
const ll M = 1e9 + 7;
int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };
vector< int > a( mx );

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

void update(int new_value,int P,int N,vector< vector <int > > &v){

    int block = P / N;
    int pos = 0;
    int old = a[ P ];
    a[ P ] = new_value;

    while(v[ block ][ pos ] < old ) pos++;

    v[ block ][ pos ] = new_value;

    if(old >= new_value)
        while(pos > 0 && v[ block ][ pos ] < v[ block ][ pos - 1 ])
            swap(v[ block ][ pos ],v[ block ][ pos - 1 ]),pos--;
    else
        while(pos < v[ block ].size()-1 && v[ block ][ pos ] > v[ block ][ pos + 1 ])
            swap(v[ block ][ pos ],v[ block ][ pos + 1 ]),pos++;

}
ll Query(int L,int R,int V,int N,vector< vector< int > >  &v){

    int block_l = L / N,block_r = R / N;
    int ans = 0;

    if(block_l == block_r){

        lop(i,L,R+1,1) if(V > a[ i ]) ans++;
        return ans;
    }
    lop(i,L,(block_l + 1) * N,1) if(V > a[ i ]) ans++;
    lop(i,block_r * N,R+1,1) if(V > a[ i ]) ans++;
    lop(i,block_l + 1,block_r,1) ans += lower_bound(v[ i ].begin(),v[ i ].end(),V) - v[ i ].begin();
    return ans;
}
int main(){

    file();
   // op

    int n,q,u;

    while(scanf("%d %d %d",&n,&q,&u) == 3){

        int root = sqrt( n ) + 1;
        vector< vector < int > > v(root+1);

        lop(i,0,n,1){

            scanf("%d",&a[ i ]);
            v[ i / root ].p_b( a[ i ] );
        }
        lop(i,0,root,1) sort(v[ i ].begin(),v[ i ].end());
        while( q-- ){

            int L,R,V,P;
            scanf("%d %d %d %d",&L,&R,&V,&P);
            L--,R--,P--;
            ll K = Query(L,R,V,root,v);
            ll new_value = (K * u)/(R - L + 1);
            if(a[ P ] != K) update(new_value,P,root,v);
            a[ P ] = new_value;
        }
        lop(i,0,n,1) printf("%d\n",a[ i ]);
    }

    return 0;
}

