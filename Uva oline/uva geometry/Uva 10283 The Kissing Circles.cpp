#include<bits/stdc++.h>
#include<math.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define f first
#define s second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define scl( n ) scanf("%lld",&n)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define sc3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define Lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

struct data{

    int x,y,c;
    data(){}
    data(int x) { this -> x = x; }
    data(int x,int y) { this -> x = x,this -> y = y; }
    data(int x,int y,int c) { this -> x = x,this -> y = y,this -> c = c; }

    bool operator < (const data &a) const {

        return c > a.c;
    }
};

ll gcd(ll a,ll b){

    if( !b ) return a;
    return gcd(b,a%b);
}


const int N = 1e6;
const int inf = 1e9;
const ll mx = 1e18;
const ll mxx = -1e18;
const int mod = 1e9 + 7;

int X[ ] = {0,0,1,-1};
int Y[ ] = {1,-1,0,0};
int X_[ ] = {0,0,1,-1,1,-1,1,-1};
int Y_[ ] = {1,-1,0,0,-1,1,1,-1};
int hx[ ] = {2,2,1,1,-2,-2,-1,-1};
int hy[ ] = {1,-1,2,-2,1,-1,2,-2};

int main(){

    file();
    db R,n;

    while(cin >> R >> n){

        if(n == 1){
            cout << fixed << setprecision(10);
            cout << R << " " << 0.0 << " " << 0.0 << endl;
            continue;
        }
        db area_of_big_circle = pi * R * R;

        db angle = 360.0 /(n*2.0);
        angle = (angle * (pi / 180.0)); /// radius to degree convert

        db r = (sin(angle) * R) / (1.00 + sin(angle));

        db area_of_little_circle = pi * r * r;

        db a = R - r;
        db b = r;
        db c = a*cos(angle); /// third edge.
        db s = (a + b + c) / 2.00;
        db angleA = 180.0 - (360.0 / (n*2) + 90.0); /// angle of small triangle
        db circle_cap = (area_of_little_circle / 360.0) * angleA; /// little circle Cap in triangle.

        db area_of_midlle = 2 * n * (sqrt( s * (s - a) * (s - b) * (s - c) ) - circle_cap);
        db area_of_low = area_of_big_circle - (n * area_of_little_circle + area_of_midlle);

        cout << fixed << setprecision(10);
        cout << r << " " << area_of_midlle << " " << area_of_low <<  endl;
    }

    return 0;
}
