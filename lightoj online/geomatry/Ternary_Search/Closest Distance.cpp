#include<bits/stdc++.h>
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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin)
#define mn 0.0000001

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

struct point{

    db x,y;
};
int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

point pp[ 4 ];

db dis(point a,point b){

    db val = ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

    return sqrt(val);
}

db T_S(){

    db a,b;

    a = dis(pp[ 0 ],pp[ 2 ]);
    b = dis(pp[ 1 ],pp[ 3 ]);

    while(abs(a-b) > mn){

        point fa,lb;
        point fc,ld;

        fa.x = (2 * pp[ 0 ].x + pp[ 1 ].x) / 3.0;
        fa.y = (2 * pp[ 0 ].y + pp[ 1 ].y) / 3.0;
        lb.x = (pp[ 0 ].x + 2 * pp[ 1 ].x) / 3.0;
        lb.y = (pp[ 0 ].y + 2 * pp[ 1 ].y) / 3.0;

        fc.x = (2 * pp[ 2 ].x + pp[ 3 ].x) / 3.0;
        fc.y = (2 * pp[ 2 ].y + pp[ 3 ].y) / 3.0;
        ld.x = (pp[ 2 ].x + 2 * pp[ 3 ].x) / 3.0;
        ld.y = (pp[ 2 ].y + 2 * pp[ 3 ].y) / 3.0;

        a = dis(fa,fc);
        b = dis(lb,ld);

        if(b < a) { pp[ 0 ] = fa,pp[ 2 ] = fc; }
        else { pp[ 1 ] = lb,pp[ 3 ] = ld; }
    }

    return abs(a + b) / 2.0;
}

int main(){

    file();

    int n;

    cin >> n;

    Case( n ){

        for(int i = 0; i < 4; i++) cin >> pp[ i ].x >> pp[ i ].y;

        db res = T_S();

        cout << fixed << setprecision(7);
        cout << "Case " << cs << ": " << res << endl;
    }
    return 0;
}
