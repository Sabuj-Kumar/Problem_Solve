#include<bits/stdc++.h>
#define ll long long
#define ull unsinged long long
#define dob double
#define pi acos(-1)
#define pii pair<int,int>
#define pll pair< ll,ll >
#define f first
#define s second
#define lop(i,v,n,j) for(int i = v; i < n; i += j)
#define lop_(i,v,n,j) for(int i = n - 1; i >= 0; i -= j)
#define in freopen("in.txt","r",stdin)
#define optimizer ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,cost;
    data(){}
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }
    bool operator < ( const data &a ){
        return cost > a.cost;
    }
};

const int mx = 1e6;
const int mx_ = 1e9;
const ll mx__ = 1e18;
int sc() { int n; scanf("%d",&n); return n; }
ll sc_() { ll n; scanf("%lld",&n); return n; }
void pf(int cs,int ans) { printf("Case %d: %d\n",cs,ans); }

vector< int > temp_array(string p){

    vector< int > temp(p.size());
    int i = 0,index = -1;
    temp[ i ] = -1;

    while(i < p.size()){

        if(index >= 0 && p[ i ] != p[ index ]) index = temp[ index ];

        i++,index++;

        temp[ i ] = index;
    }
    return temp;
}

int KMP(string s,string p){

    int count_ = 0,i = 0,index = 0;
    vector < int > temp = temp_array( p );

    while(i < s.size()){

        while(index >= 0 && s[ i ] != p[ index ]) index = temp[ index ];

        i++,index++;

        if(index == p.size()) index = temp[ index ],count_++;
    }
    return count_;
}
int main(){

    file();
//    optimizer;

    int test;

    test = sc();

    lop(i,1,test+1,1){

        char s[ mx+5 ],p[ mx+5 ];

        scanf("%s %s",s,p);

        pf(i,KMP(s,p));
    }
    return 0;
}
