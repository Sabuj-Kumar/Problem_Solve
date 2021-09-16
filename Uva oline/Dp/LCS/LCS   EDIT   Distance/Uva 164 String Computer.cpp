#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pii pair< int,int >
#define pll pair< ll,ll >
#define pb push_back
#define pf push_back
#define f first
#define s second
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base:sync_with_stdio(0);cin.tie(0);cou.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;

    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const{

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}

ll big(ll n,ll p,ll m){

    if( !p ) return 1;

    if( !(p % 2) ){

        ll x = big(n,p/2,m);
        return (x * x) % m;
    }
    ll x = big(n,p-1,m);
    return ( (n % m) * x ) % m;
}

int X[ ] = {0,0,1,-1,1,-1,1,-1};
int Y[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const ll mod = 1e9 + 7;

string s,p,out;
int dp[ 25 ][ 25 ],path[ 25 ][ 25 ];
int relpos,ind,ls,lp;

int distance(int i,int j){

    if(i == ls) return lp - j;
    if(j == lp) return ls - i;

    if(dp[ i ][ j ] != -1) return dp[ i ][ j ];

    if(s[ i ] == p[ j ]) dp[ i ][ j ] = distance(i + 1,j + 1);
    else{

        int a = 1 + distance(i,j + 1);
        int b = 1 + distance(i + 1,j);
        int c = 1 + distance(i + 1,j + 1);

        if(a <= b and a <= c){

            dp[ i ][ j ] = a;
            path[ i ][ j ] = 1;
        }
        else if(b <= a and b <= c){

            dp[ i ][ j ] = b;
            path[ i ][ j ] = 2;
        }
        else {

            dp[ i ][ j ] = c;
            path[ i ][ j ] = 3;
        }
    }
    return dp[ i ][ j ];
}

void path_print(int i,int j){

    if(i == ls){

        while( j < lp ){

            cout << "I" << p[ j ];

            if(j < 9) cout << "0";

            cout << j + 1;
            j++;
        }
        return;
    }
    if(j == lp){

        while(i < ls){

            cout << "D" << s[ i ];

            if(lp < 9) cout << "0";

            cout << lp + 1;
            i++;
        }
        return;
    }

    if( !path[ i ][ j ] ) path_print(i + 1,j + 1);

    else if( path[ i ][ j ] == 1 ){

        cout << "I" << p[ j ];
        if(j < 9) cout << "0";
        cout << j + 1;

        path_print(i,j + 1);
    }
    else if(path[ i ][ j ] == 2){

        cout << "D" << s[ i ];
        if(j < 9) cout << "0";
        cout << j + 1;

        path_print(i + 1,j);
    }
    else{

        cout << "C" << p[ j ];
        if(j < 9) cout << "0";
        cout << j + 1;

        path_print(i + 1,j + 1);
    }
    return;
}
int main(){

    file();

    while(cin >> s) {

        if(s == "#") break;

        cin >> p;

        ls = s.size();
        lp = p.size();

        memset(dp,-1,sizeof dp);
        memset(path,0,sizeof path);

        distance(0,0);
        path_print(0,0);
        cout << "E" << endl;
    }
    return 0;
}

