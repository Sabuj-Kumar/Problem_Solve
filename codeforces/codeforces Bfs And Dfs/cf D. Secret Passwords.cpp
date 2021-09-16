#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define p_b push_back
#define p_f push_front
#define lop(v,n) for(int i = v; i < n; i++)
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

    int x,y,z;
    data(){}
    data(int x,int y){ this->x = x,this->y = y; }
    data(int x,int y,int z) { this-> x = x, this-> y = y,this-> z = z; }
//    bool operator < (const data &a) const{
//
//        return z > a.z;
//    }
};

const int sz = 1e5;
const int inf = 1e9;
const ll mx = 1e18;
const ll inf_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};

int sc() { int n; scanf("%d",&n); return n; }

vector < int > graph[ 30 ];
int vis[ 26+5 ];

void dfs(int source){

    if(vis[ source ] == 1) return;

    vis[ source ] = 1;

    for( auto x : graph[ source ] ) dfs( x );
}
int main (){

    file();

    int n = sc();
    memset(vis,-1,sizeof vis);
    unordered_map< int ,int > mp;
    int c = 0;

    Lop(cs,0,n,1){

        string ch;
        cin >> ch;
        mp[ ch[ 0 ] - 'a' ] = 1;

        if(ch.size() == 1) graph[ ch[ 0 ] - 'a' ].p_b( ch[ 0 ] - 'a' );

        else {

            lop(1,ch.size()) {

                 graph[  ch[ 0 ] - 'a' ].p_b( ch[ i ] - 'a'  );
                 graph[ ch[ i ] - 'a' ].p_b( ch[ 0 ] - 'a'  );
                 mp[ ch[ i ] - 'a'  ] = 1;
            }
        }
    }

    lop(0,26){

        if(vis[ i ] == -1 && mp[ i ]) {

            c++;
            dfs( i );
        }
    }
    cout << c << endl;

    return 0;
}
