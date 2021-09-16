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
#define lop(v,n) for(int i = v; i < n; i += 1)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define in freopen("in.txt","r",stdin);
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

int sc(){ int n; cin >> n; return n; }
ll scl(){ ll n; cin >> n; return n; }
ull scu(){ ull n; cin >> n; return n; }
string scs(){ string s; cin >> s; return s; }
string scss(){ string s; getline(cin,s); return s; }

int main(){

    //file();

    int t = sc();

    while( t-- ){

        string s,p;
        cin >> p;
        cin >> s;
        int f = 0,a = p.size(),b = s.size();

        sort(p.begin(),p.end());
        map< char,int > mp;

        for(int i = 0; i < a; i++) mp[ p[ i ] ] = 1;

        for(int i = 0; i < b; i++){

            if(mp[ s[ i ] ]){

                string ch;

                if(i + a <= b) for(int k = i; k < i + a; k++) ch += s[ k ];
                else break;

                sort(ch.begin(),ch.end());

                if(ch == p) {

                    f = 1;
                    break;
                }
            }
        }

        if( f ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}

