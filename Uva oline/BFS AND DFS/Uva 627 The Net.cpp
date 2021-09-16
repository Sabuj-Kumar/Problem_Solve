#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define p_b push_back
#define p_f push_front
#define f first
#define s second
#define sc scanf
#define pf printf
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
    data(int x_,int y_) { x = x_,y = y_; }
    data(int x_,int y_,int cost_) { x = x_,y = y_,cost = cost_; }

//    bool operator < (const data &a) const{
//
//        return cost > a.cost;
//    }
};

const int inf = 1e6;
const int inf_ = 1e9;
const ll mx = 1e18;
const ll mx_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,1,-1,-1,1};

vector< vector< int > > graph;
int vis[ 303 ];
int parent[ 303 ];
stack < int > sk;

void bfs(int s,int d){

    queue< int > q;
    q.push( s );
    vis[ s ] = 0;

    while(!q.empty()){

        int p = q.front();
        q.pop();

        for(auto x : graph[ p ]){

            if(vis[ x ] == -1){

                vis[ x ] = vis[ p ] + 1;
                parent[ x ] = p;
                q.push( x );
            }
            if(x == d) return;
        }
    }
}

void search_parent(int n){

    sk.push( n );

    if(parent[ n ] != -1) return search_parent( parent[ n ] );
}
int main(){

    file();

    int node;
    while(cin >> node){

        int f,n,m,query;
        string s;
        vector< vector< int > > temp(node+2);
        swap(temp,graph);
        lop(i,0,node,1){

            cin >> s;
            int si = s.size();
            m = 0;
            n = 0;
            f = 0;
            lop(j,0,si,1){

                if(s[ j ] != '-' && s[ j ] != ',') {

                    while(s[ j ] != '-' && s[ j ] != ',' && j < si)
                        m = (m * 10) + (s[ j ] - 48),j++;
                }
                if(m != 0 && !f) n = m,f = 1;

                else if( f && m ) graph[ n ].p_b( m );

                m = 0;
            }
        }

        pf("-----\n");
        sc("%d",&query);

        while(query--){

            sc("%d %d",&n,&m);
            memset(vis,-1,sizeof vis);
            memset(parent,-1,sizeof parent);
            bfs(n,m);
            f = 0;
            if(parent[ m ] != -1){

                search_parent( m );
                while(!sk.empty()){

                    if(f) cout << " "<< sk.top();
                    else cout << sk.top();
                    sk.pop();
                    f = 1;
                }
            }
            else cout << "connection impossible";
            cout << endl;
        }
    }
    return 0;
}
