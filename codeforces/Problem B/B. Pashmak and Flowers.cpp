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
#define op ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define in freopen("in.txt","r",stdin);

using namespace std;

void file(){

    #ifndef ONLINE_JUDGE
    in
    #endif // ONLINE_JUDGE
}

int I() { int n; sc( n ); return n; }
ll Il() { ll  n; sl( n ); return n; }

int main(){

    file();

    ll n;
    cin >> n;

    ll a[ n + 5 ];

    for(int i = 0; i < n; i++)cin >> a[ i ];

    sort(a,a+n);

    if(a[ 0 ] == a[ n - 1 ]) {

        ll pr = n * (n - 1) / 2;

        cout << 0 << " " << pr << endl;
    }

    else {

        ll cntf = 0,cnts = 0,f = a[ 0 ],s = a[ n - 1 ];

        for(cntf = 0;f == a[ cntf ]; ++cntf);
        for(int i = n - 1; s == a[ i ]; --i) cnts++;

        cout << a[ n - 1 ] - a[ 0 ] << " "<< cntf * cnts << endl;
    }

    return 0;
}


