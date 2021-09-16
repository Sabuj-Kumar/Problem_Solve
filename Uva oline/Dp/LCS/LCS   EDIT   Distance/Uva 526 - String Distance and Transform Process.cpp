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

string s,p;
int table[ 85 ][ 85 ],path[ 85 ][ 85 ];
int relpos,ind,lens,lenp;

int distance(int lns,int lnp){

    if(lns == lens) return lenp - lnp;
    if(lnp == lenp) return lens - lns;

    if(table[ lns ][ lnp ] != -1) return table[ lns ][ lnp ];

    if(s[ lns ] == p[ lnp ]) table[ lns ][ lnp ] = distance(lns + 1,lnp + 1);
    else{

        int a = 1 + distance(lns,lnp + 1);
        int b = 1 + distance(lns + 1,lnp);
        int c = 1 + distance(lns + 1,lnp + 1);

        if(a <= b and a <= c){

            table[ lns ][ lnp ] = a;
            path[ lns ][ lnp ] = 1;
        }
        else if(b <= a and b <= c){

            table[ lns ][ lnp ] = b;
            path[ lns ][ lnp ] = 2;
        }
        else {

            table[ lns ][ lnp ] = c;
            path[ lns ][ lnp ] = 3;
        }
    }
    return table[ lns ][ lnp ];
}

void print(int i,int j){

    if(i == lens){

        while(j < lenp){

            cout << ++ind << " Insert " << j + 1 << "," << p[ j ] << endl;
            j = j + 1;
        }
        return;
    }
    if(j == lenp){

        while(i < lens){

            cout << ++ind << " Delete " << i + 1 + (relpos--) << endl;
            i = i + 1;
        }
        return;
    }

    if( !path[ i ][ j ] ) print(i + 1,j + 1);
    else if(path[ i ][ j ] == 1){

        cout << ++ind << " Insert " << j + 1 << "," << p[ j ] << endl;
        relpos++;
        print(i,j + 1);
    }
    else if(path[ i ][ j ] == 2){

        cout << ++ind << " Delete " << i + 1 + relpos << endl;
        relpos--;
        print(i + 1,j);
    }
    else{

        cout << ++ind << " Replace " << j + 1 << "," << p[ j ] << endl;
        print(i+1,j+1);
    }
    return;
}
int main(){

    file();

    bool flag = 0;

    while(getline(cin,s)){

        getline(cin,p);

        if( flag ) cout << endl;
        else flag = 1;
        lens = s.size();
        lenp = p.size();

        memset(table,-1,sizeof table);
        memset(path,0,sizeof path);

        int dis = distance(0,0);
        ind = 0;
        relpos = 0;
        cout << dis << endl;
        print(0,0);
    }

    return 0;
}
