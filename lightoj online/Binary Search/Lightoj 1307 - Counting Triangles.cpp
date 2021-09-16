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

    int x,y,c;
    data(){}
    data(int x,int y) { this->x = x,this->y = y;}
    data(int x,int y,int c) {this-> x = x,this-> y = y, this-> c = c; }
    bool operator < (const data &a) const{

        return c > a.c;
    }
};

const int siz = 1e6;
const int mx = 1e9;
const ll inf = 1e18;
const ll inf_ = -1e18;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int XX[ ] = {0,0,1,-1,1,-1,1,-1};
int YY[ ] = {1,-1,0,0,1,1,-1,-1};
int gx[ ] = {1,1,2,2,-1,-1,-2,-2};
int gy[ ] = {2,-2,1,-1,2,-2,1,-1};

vector< int > vec;

int sc() { int n; cin >> n; return n; }

int main(){

    op
    file();

    int test = sc();

    Lop(cs,1,test+1,1){

        int n = sc();
        vector< int > v( n );
        swap(v,vec);

        lop(0,n) vec[ i ] = sc();

        sort(vec.begin(),vec.end());

        int ans = 0;

        lop(0,n)Lop(j,i+1,n,1){

            int val = (vec[ i ] + vec[ j ]-1);

            int ck = upper_bound(vec.begin(),vec.end(),val)-vec.begin();

            ans += ck - j - 1;
        }

        cout <<"Case "<< cs <<": "<< ans << endl;
    }

    return 0;
}
