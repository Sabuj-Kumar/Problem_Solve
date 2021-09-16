#include<bits/stdc++.h>
#define ll long long
#define ull unsinged long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define db double
#define ldb long double
#define pi acos(-1)
#define p_b push_back
#define p_f push_front
#define f first
#define s second
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
const int N = 1e6 + 7;
const ll P = 1e8 + 5e4 + 1;
const ll INVP = 678791932; // P inverse modulo M
const ll M = 1e9 + 7;

int X[ ] = { 0,0,1,-1 };
int Y[ ] = { 1,-1,0,0 };
int X_[ ] = { 0,0,1,-1,1,-1,1,-1 };
int Y_[ ] = { 1,-1,0,0,1,-1,-1,1 };
ll PW[ N ],INV[ N ],HASH[ N ];

void calculation(){

    PW[ 0 ] = INV[ 0 ] = 1;

    lop(i,1,N,1){

        PW[ i ] = (PW[ i - 1 ] * P) % M;
        INV[ i ] = (INV[ i - 1 ] * INVP) % M;
    }
}

void init(string &s){

    HASH[ 0 ] = 0;
    int n = s.size();
    lop(i,0,n,1) HASH[ i + 1 ] = (HASH[ i ] + PW[ i ] * s[ i ]) % M;
}
ll HASH_VALUE(int L,int R){

    ll ans = ((HASH[ R + 1 ] - HASH[ L ]) * INV[ L ]) % M;
    if(ans < 0) ans += M;
    return ans;
}
int main(){

    file();
    op
    calculation();
    int test,cs = 0;
    while(cin >> test){

        string s,p;
        cin >> p >> s;
        int n = s.size();
        int m = p.size();
        if(cs++) cout << endl;
        init( p );
        int value = HASH_VALUE(0,m-1);
        init( s );
        lop(i,0,n-m+1,1){

            if(HASH_VALUE(i,i+m-1) == value) cout << i << endl;
        }
    }
    return 0;
}
