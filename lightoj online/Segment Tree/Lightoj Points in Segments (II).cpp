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
#define sl( n ) scanf("%d",&n)
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

int main(){

    file();

    int T;

    sc( T );

    Case( T ){

        int v,n,q;
        vector< int > start,end_;

        sc( n );
        sc( q );

        for(int i = 0; i < n; i++){

            int l,r;

            sc( l );
            sc( r );

            start.pb(l);
            end_.pb(-r);
        }

        sort(start.begin(),start.end());
        sort(end_.begin(),end_.end());

        printf("Case %d:\n",cs);

        while( q-- ){

            sc( v );

            int a = start.end() - upper_bound(start.begin(),start.end(),v);
            int b = end_.end() - upper_bound(end_.begin(),end_.end(),-v);

            cout << n - a - b << endl;
        }
    }
    return 0;
}
