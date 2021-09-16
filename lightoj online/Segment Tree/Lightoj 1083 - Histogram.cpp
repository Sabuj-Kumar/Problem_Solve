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
#define in freopen("input.txt","r",stdin)
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in;
    #endif // ONLINE_JUDGE
}

const int N = 50000;
int n;
int tree[ 4 * N ];
int ar[ N ];

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

void build(int node,int L,int R){

    if(L == R){

        tree[ node ] = L;
        return;
    }

    int mid = (L + R) / 2;
    build(node * 2,L,mid);
    build(node * 2 + 1,mid + 1,R);

    if(ar[ tree[ node * 2 ] ] <= ar[ tree[ node * 2 + 1 ] ])tree[ node ] = tree[ node * 2 ];
    else tree[ node ] = tree[ node * 2 + 1 ];
}

int query(int node,int L,int R,int x,int y){

    if(x > y) return 0;

    if(x == L and y == R) return tree[ node ];

    int mid = (L + R) / 2;

    int p = query(node * 2,L,mid,x,min(y,mid));
    int q = query(node * 2 + 1,mid + 1,R,max(x,mid + 1),y);

    if(p == 0) return q;
    if(q == 0) return p;

    if(ar[ p ] <= ar[ q ]) return p;
    return q;
}

int cal(int L,int R){

    if(R < L) return 0;

    int ans = query(1,1,n,L,R);

    int area = (R - L + 1) * ar[ ans ];

    int area1 = cal(L,ans-1);
    int area2 = cal(ans + 1,R);

    return max(area,max(area1,area2));
}
int main(){

    file();

    int t = I();

    Case( t ){

        n = I();

        for(int i = 1; i <= n; i++) ar[ i ] = I();

        build(1,1,n);

        cout << "Case " << cs << ": " << cal(1,n) << endl;
    }

    return 0;
}
