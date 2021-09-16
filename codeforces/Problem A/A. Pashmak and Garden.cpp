#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull unsigned long long
#define db double
#define ldb long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define ft first
#define sd second
#define pb push_back
#define pf push_front
#define sc( n ) scanf("%d",&n)
#define sl( n ) scanf("%lld",&n)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
#define lop(i,v,n) for(int i = v; i < n; i++)
#define in freopen("in.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    int x1 = I(),y1 = I();
    int x2 = I(),y2 = I();

    if(x1 == x2){

        int d = abs(y1 - y2);

        cout << x1 + d << " " << y1 << " " << x2 + d<< " " << y2 << endl;
    }
    else if(y1 == y2){

        int d = abs(x1 - x2);

        cout << x1 << " " << y1 + d << " " << x2 << " " << y2 + d << endl;
    }
    else if(abs(x1 - x2) == abs(y1 - y2)){

        int x3 = x2;
        int x4 = x1;
        int y3 = y1;
        int y4 = y2;

        cout << x3 << " " << y3 <<" " << x4 << " " << y4 << endl;
    }
    else cout << -1 << endl;

    return 0;
}

