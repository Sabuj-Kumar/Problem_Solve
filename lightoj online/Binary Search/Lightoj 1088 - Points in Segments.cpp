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
#define in freopen("in.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lop(v,n) for(int i = v; i < n; i++)
#define Lop(i,v,n,j) for(int i = v; i < n; i += j)
#define CS(n) for(int cs = 1; cs <= n; cs++)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;
    data(){}
    data(int x,int y) { this->x = x,this->y = y; }
    data(int x,int y,int c) { this-> x = x,this -> y = y,this -> c = c; }
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int sz = 1e6;
const int mx = 1e9;
const ll inf = 1e18;
const ll inf_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int Hx[ ] = {1,-1,2,-2,1,-1,2,-2};
int Hy[ ] = {2,-2,1,-1,-2,2,-1,1};

int sc() { int n; scanf("%d",&n); return n; }

int main(){

    //op
    file();

    int t = sc();

    CS(t){

        int n = sc(),m = sc();
        int vec[ n ];

        lop(0,n) vec[ i ] = sc();

        printf("Case %d:\n",cs);
        while( m-- ){

            int x = sc(),y = sc();
            int low = lower_bound(vec,vec+n,x)-vec;
            int up = upper_bound(vec,vec+n,(y-1))-vec;
            int ans = 0;
            if(vec[ up ] == y) ans = (up - low + 1);
            else ans = (up - low);
            printf("%d\n",ans);
        }
    }

    return 0;
}
