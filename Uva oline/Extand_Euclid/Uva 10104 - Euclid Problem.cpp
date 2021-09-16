#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int GCD(int a, int b, int &x, int &y){

    if (b == 0) {

        x = 1;
        y = 0;

        return a;
    }

    int x1, y1;
    int d = GCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

int main(){

    file();

    int a,b;

    while(cin >> a >> b){

        int x,y;

        int gcd = GCD(a,b,x,y);

        cout << x << " " << y << " " << gcd << endl;
    }

    return 0;
}
