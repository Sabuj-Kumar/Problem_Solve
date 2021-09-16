#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
#define ull usigned long long
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
#define lop(i,v,n) for(int i = v; i < n; i++)
#define Case( n ) for(int cs = 1; cs <= n; cs++)
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

int main() {

    file();

    int t = I();

    Case( t ) {

        ll p = Il();
        ll l = Il();

        ll s = p-l;

        cout <<"Case " << cs << ": ";
        if(s <= l) puts("impossible");
        else{

            vector< ll > v;

            for(int i = 1; i <= sqrt( s ); i++){

                if(!(s % i)){

                    ll x = s/i;

                    if(i > l) v.pb( i );

                    if(i != x and x > l) v.pb( x );
                }
            }

            sort(v.begin(),v.end());

            for(int i = 0; i < v.size(); i++) {

                cout << v[ i ];

                if(i < v.size()-1) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
