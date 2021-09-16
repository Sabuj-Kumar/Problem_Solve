#include<bits/stdc++.h>
#define ll long long
#define ull unsinged long long
#define db double
#define ldb long double
#define pi acos(-1)
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_front
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n-1; i >= 0; i -= j)
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

struct data {

    int x,y,cost;
    data () {}
    data(int x_,int y_,int cost_){ x = x_,y = y_; cost = cost_; }
    bool operator < (const data &a) const{

        return cost > a.cost;
    }
};

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

const int mx = 1e6;
const int mx_ = 1e9;
const ll mx__ = 1e18;

int sc() { int n; cin >> n; return n; }
ll sc_() { ll n; cin >> n; return n; }
string sc__() { string s; cin >> s; return s; }
string sc___() { string s; getline(cin,s); return s; }
void pf(int cs,int n,ll ans) { printf("Case %d: %lld\n",cs,2*n - ans); }

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

//    op
    //file();

    int test = sc();
    cin.ignore();
    lop(i,1,test+1,1){

        string s = sc___();
        int n = s.length();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int ans = KMP(s,s1);
        pf(i,n,ans);
    }
    return 0;
}
