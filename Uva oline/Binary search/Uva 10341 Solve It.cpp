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
#define Lop(i,v,nj) for(int i = v; i < n; i += j)
#define in freopen("input.txt","r",stdin);
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;
    data(){}
    data(int x,int y) { this->x = x,this-> y = y; }
    data(int x,int y,int c) { this->x = x,this->y = y,this->c = c; }
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int inf = 1e9;
const int mx = 1e6;
const ll infl = 1e18;
const ll mxl = -1e18;
const db ck = 1e-6;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};

db scd() { db n; cin >> n; return n; }
int sc() { int n; cin >> n; return n; }

db p,q,r,s,t,u;

db cal( db x ){

    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

db binary(){

    db L = 0.0,R = 1.0;

    while(L < R){

        db mid = (L + R) / 2.0;
        db ans = cal( mid );
        if(fabs(ans) < ck) return mid;
        if(ans > ck) L = mid;
        else R = mid;
    }
    return -1.0;
}
int main(){

    op
    file();

    while(cin >> p >> q >> r >> s >> t >> u){

        if(!p&&!q&&!r&&!s&&!t&&!u) cout << 0.0000 << endl;

        else {

            db ans = binary();
            if(ans == -1.0) cout << "No solution" << endl;
            else cout << fixed << setprecision(4)<< ans << endl;
        }
    }

    return 0;
}
